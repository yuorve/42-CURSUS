#!/bin/bash

cd /var/www/html/

if [ ! -f wp-config.php ]; then
	echo "Downloading Wordpress..." > log.out
	wp core download --allow-root
	echo "Installing Wordpress..." > log.out
	wp config create --allow-root --dbname=$SQL_DB --dbuser=$SQL_USER --dbpass=$SQL_PWD --dbhost=mariadb --path='/var/www/html'	
	wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
	echo "Creating User..." > log.out
	wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root
	echo "Installing Theme..." > log.out
	wp theme install variations --activate --allow-root
	echo "Wordpress Ready." > log.out
fi

mkdir /run/php
/usr/sbin/php-fpm7.4 -F