FROM	debian:11

RUN	apt update -y && apt upgrade -y
RUN	apt install -y php7.4 php-fpm php-mysql mariadb-client curl
RUN	mkdir -p /var/www/html
RUN	adduser -D -H -S -G www-data www-data
RUN	chown -R www-data:www-data /var/www/html
RUN	cd /var/www/html
RUN curl -O https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php

COPY	conf/www.conf /etc/php/7.4/fpm/pool.d
