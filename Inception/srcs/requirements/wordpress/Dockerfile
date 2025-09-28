FROM debian:bullseye

RUN apt-get update && apt-get install -y \
	php7.4-fpm \
	php7.4-mysql \
	mariadb-client \
	curl \
	&& rm -rf /var/lib/apt/lists/*

# template web page
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php && \
	sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf

WORKDIR /var/www/html

COPY ./conf/wp-setup.sh /wp-setup.sh

RUN chmod +x /wp-setup.sh

EXPOSE 9000

ENTRYPOINT ["sh", "/wp-setup.sh"]
