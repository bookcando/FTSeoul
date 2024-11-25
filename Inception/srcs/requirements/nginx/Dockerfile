
FROM	alpine:3.17

RUN		apk update && apk upgrade && \
		apk add nginx openssl dumb-init

RUN		mkdir -p /var/www/html/
RUN 	mkdir -p /run/nginx
RUN 	mkdir -p /etc/nginx/ssl/

RUN 	addgroup -g 9642 my_group && \
 		adduser -D -H -u 9650 -G my_group my_nginxuser && \
		sed -i 's/user nginx;/user my_nginxuser my_group;/g' /etc/nginx/nginx.conf

RUN		chown -R my_nginxuser:my_group /run/nginx/ && \
		chown -R my_nginxuser:my_group /var/www/html/
# https://wiki.alpinelinux.org/wiki/Nginx

COPY	./conf/my.conf /etc/nginx/http.d/my.conf

RUN		openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout /etc/nginx/ssl/minsulee.key \
		-out /etc/nginx/ssl/minsulee.crt \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Cadet/CN=minsulee" \
		-addext 'subjectAltName=DNS:minsulee.42.fr'
# https://www.digicert.com/kb/ssl-support/openssl-quick-reference-guide.htm
# request, x509 type(structure) of new self-signed certificate,
# nodes for no passphrase(no need to type password when you start server), 
# days for expiration date, 
# keyout for key file, out for certificate file
# subject for who is the certificate for
# stackoverflow : When creating a SSL certificate should the common name be the domain name or IP address?
# -> currently, no browser care about CN, and don't expect CN to be the domain name
# -> but, if you want to use, you should use SAN : subjectAltName

EXPOSE	443

ENTRYPOINT	[ "dumb-init", "--", "nginx", "-g", "daemon off;"]
# CMD			["-g", "daemon off;"]
