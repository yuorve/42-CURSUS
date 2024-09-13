#!/bin/bash

service mariadb start

while ! mariadb-admin ping -hlocalhost --silent;
do
	echo "Waiting to mariadb..."
	sleep 1
done

if [ ! -d /var/lib/mysql/${SQL_DB} ]; then
	sh /create.sh
else
	mariadb-admin -u root -p${SQL_ROOT_PWD} -hlocalhost shutdown
fi

exec mysqld_safe