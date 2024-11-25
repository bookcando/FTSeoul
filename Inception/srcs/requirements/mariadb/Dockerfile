FROM	alpine:3.17

RUN		apk update && apk upgrade &&\
		apk add mariadb mariadb-client dumb-init

# MariaDB configuration file
COPY		./tools/launch_mariadb.sh /tmp/launch_mariadb.sh
RUN		chmod +x /tmp/launch_mariadb.sh

RUN       	mkdir -p /run/mysqld
RUN       	chown -R mysql:mysql /run/mysqld

# Run MariaDB configuration script as entry point
# ENTRYPOINT	[ "sh", "/tmp/launch_mariadb.sh" ]
ENTRYPOINT	[ "dumb-init", "--", "sh", "/tmp/launch_mariadb.sh" ]
