#!/bin/sh

cd /var/www/html

if [ ! -f "wp-config.php" ]; then
	# wp core files
    wp core download --allow-root

	# wp config file pointing to mdb
    wp config create --allow-root \
        --dbname=${DB_NAME} \
        --dbuser=${DB_USER} \
        --dbpass=${DB_PASSWORD} \
        --dbhost=mariadb \
        --path=/var/www/html

	# wp init
    wp core install --allow-root \
        --url=https://${DOMAIN_NAME} \
        --title=${WP_TITLE} \
        --admin_user=${WP_ADMIN} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL}

	# wp add user
    wp user create --allow-root \
        ${WP_USER} ${WP_USER_EMAIL} \
        --user_pass=${WP_USER_PASSWORD} \
        --role=author
fi

exec php-fpm7.4 -F