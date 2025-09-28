FROM debian:bullseye

RUN apt-get update && apt-get install -y \
	nginx \
	openssl

RUN mkdir -p /etc/nginx/ssl && \
	openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
	-keyout /etc/nginx/ssl/mzarichn.key \
	-out /etc/nginx/ssl/mzarichn.crt \
	-subj "/C=PT/ST=Lisboa/L=Lisboa/O=42Lisboa/OU=42/CN=mzarichn.42.fr"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# default 80
EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]