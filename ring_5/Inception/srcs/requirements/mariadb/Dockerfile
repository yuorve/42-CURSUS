FROM	debian:11

RUN	apt update -y && apt upgrade -y
RUN	apt install -y mariadb-server

RUN mkdir -p /var/run/mysqld/
RUN touch /var/run/mysqld/mysqld.sock
RUN chown mysql:mysql -R /var/run/mysqld/
RUN chmod -R 755 /var/run/mysqld/

COPY	conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY	tools/init.sh /
COPY	tools/create.sh /
RUN     chmod +x /init.sh
RUN     chmod +x /create.sh
EXPOSE	3306

CMD     [ "sh", "/init.sh" ]