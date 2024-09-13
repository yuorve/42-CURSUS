FROM	debian:11

RUN	apt update -y && apt upgrade -y
RUN	mkdir -p /var/www/html
RUN	adduser -D -H -S -G www-data www-data
RUN	chown -R www-data:www-data /var/www/html

COPY	tools/ /var/www/html/
