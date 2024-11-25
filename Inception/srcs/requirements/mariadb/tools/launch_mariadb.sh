#!/bin/sh

#if [ ! -d "/run/mysqld" ]; then
#	mkdir -p /run/mysqld
#	chown -R mysql:mysql /run/mysqld
#fi
# socket file will be stored in here
# -> you need that folder pre-made
# to avoid "folder can't be made" or something...

	echo "MariaDB configuring."
	chown -R mysql:mysql /var/lib/mysql
	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql > /dev/null
cat << EOF > /tmp/config.sql
	FLUSH PRIVILEGES;
	CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE_NAME;
	CREATE USER IF NOT EXISTS '$MARIADB_DATABASE_USER'@'%' IDENTIFIED BY '$MARIADB_DATABASE_USER_PASSWORD';
	CREATE USER IF NOT EXISTS '$MARIADB_DATABASE_USER'@'localhost' IDENTIFIED BY '$MARIADB_DATABASE_USER_PASSWORD';
	GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';
	GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';
	GRANT ALL PRIVILEGES ON $MARIADB_DATABASE_NAME.* TO '$MARIADB_DATABASE_USER'@'%' WITH GRANT OPTION;
	FLUSH PRIVILEGES;
EOF
	echo "MariaDB config.sql created."
# bootstrap mode : setting up mariadb without starting it.
	/usr/bin/mysqld --user=mysql --bootstrap < /tmp/config.sql
	rm -f /tmp/config.sql
	echo "MariaDB configured"



# connecting network from outside of container (listen)
sed -i "s/skip-networking/# skip-networking/g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s/.*bind-address\s*=.*/bind-address=0.0.0.0/g" /etc/my.cnf.d/mariadb-server.cnf

# listen.owner, listen.group sets the owner and group for the Unix socket file.
# -> you can control its permission with uid & gid!
# 
# https://mariadb.com/kb/en/configuring-mariadb-for-remote-client-access/
# https://wiki.alpinelinux.org/wiki/MariaDB
# since we are using "standard" port, we don't need to set it.
# sed -i "s/.*port\s*=.*/port=${MARIADB_PORT}/g" /etc/my.cnf.d/mariadb-server.cnf
# sed -i "s/.*socket\s*=.*/socket=${DB_SOCKET}/g" /etc/my.cnf.d/mariadb-server.cnf


echo "MariaDB starting"
exec /usr/bin/mysqld_safe --user=mysql
# exec /usr/bin/mysqld --user=mysql --console
