all: 
	@mkdir -p /home/mzarichn/data/wordpress
	@mkdir -p /home/mzarichn/data/mariadb
	@docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	@docker compose -f ./srcs/docker-compose.yml down

clean:
	@docker compose -f ./srcs/docker-compose.yml down -v
	@docker system prune -af --volumes
	@docker volume prune -f
	@sudo rm -rf /home/mzarichn/data

re: clean all

status:
	@docker ps
	@echo "\nVolumes:"
	@docker volume ls

logs:
	@docker compose -f ./srcs/docker-compose.yml logs

.PHONY: all down clean re status logs