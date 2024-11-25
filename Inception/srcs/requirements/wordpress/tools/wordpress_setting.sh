#!/bin/sh

echo "Checking mariadb connection"

# try to access to mariadb -> it fails until mariadb is ready.
# this command will log into wordpress database.
# every mariadb configuration has done before turning mariadb on
# -> mariadb setting is done before booting it up,
# -> with bootstrap mode!

while ! mariadb -h${MARIADB_HOSTNAME} -u${MARIADB_DATABASE_USER} -p${MARIADB_DATABASE_USER_PASSWORD} ${MARIADB_DATABASE_NAME}
do
    sleep 2;
done
echo "MariaDB connected"

# if [ -f ${WORDPRESS_PATH}/wp-config.php ]
if [ -f /var/www/html/wp-config.php ]
then
	echo "Wordpress already configured."
else

# wait mariadb here.
# if you miss mariadb, you will get error -> 
# can't connect to server on 'mariadb'(mariadb container hostname)
# -> cofiguration will fail
# -> will cause wp-config.php not found.

# reason of putting download in here:
# wp data downloaded in image -> makes image too big.
# -> no reason to make dockerfile to share docker image/container.

 	wp-cli.phar cli update --yes --allow-root

	wp-cli.phar core download --allow-root --version=6.3.2 --path=/var/www/html

	wp-cli.phar config create --allow-root \
			--dbname=${MARIADB_DATABASE_NAME} \
			--dbuser=${MARIADB_DATABASE_USER} \
			--dbpass=${MARIADB_DATABASE_USER_PASSWORD} \
			--dbhost=${MARIADB_HOSTNAME} \
			--path=/var/www/html/ 

	wp-cli.phar core install --allow-root \
			--url=${DOMAIN_NAME} \
			--title=${WORDPRESS_TITLE} \
			--admin_user=${WORDPRESS_ADMIN_USER} \
			--admin_password=${WORDPRESS_ADMIN_PASSWORD} \
			--admin_email=${WORDPRESS_ADMIN_EMAIL} \
			--path=/var/www/html/

	wp-cli.phar user create --allow-root \
			${WORDPRESS_USER} ${WORDPRESS_USER_EMAIL} \
			--user_pass=${WORDPRESS_USER_PASSWORD} \
			--role=administrator \
			--display_name=${WORDPRESS_USER} \
			--path=/var/www/html/

	# /usr/bin/wp-cli.phar plugin install classic-editor --activate --allow-root
	# /usr/bin/wp-cli.phar plugin install really-simple-ssl --activate --allow-root
	# if wp-cli is running with root, it can create/modify files with root permission.
	# -> it can cause problems; -> modifying other files...

	chown -R my_wpuser:my_group /var/www/html/
	find /var/www/html -type d -exec chmod 755 {} \;
	find /var/www/html -type f -exec chmod 644 {} \;
	find /var/www/html/wp-content -type d -exec chmod 775 {} \;
	find /var/www/html/wp-content -type f -exec chmod 664 {} \;

	chown my_wpuser:my_group /var/www/html/wp-content/uploads
	chmod 775 /var/www/html/wp-content

	echo "Wordpress configured"
fi

# echo "[WP config] Starting WordPress fastCGI on port 9000."

# https://stackoverflow.com/questions/45497512/how-to-get-sendmail-working-in-alpine-docker-container
# sendmail doesn't work in this container -> there's no mail transfer agent.

echo "Wordpress ready"
exec /usr/sbin/php-fpm81 --nodaemonize
# exec /usr/sbin/php81-fpm --nodaemonize
