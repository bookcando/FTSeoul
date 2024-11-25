
USER := minsulee
DATA_PATH := /home/${USER}/data
CONTAINERS := nginx wordpress mariadb
IMAGES := nginx:inception wordpress:inception mariadb:inception
VOLUMES := srcs_mariadb-data srcs_wordpress-data
DB_DATAS := ${DATA_PATH}/mariadb-data ${DATA_PATH}/wordpress-data
NETWORKS := nginx-wordpress mariadb-wordpress
DOCKER_COMPOSE_FILE := ./srcs/docker-compose.yml

all : 
	make up

up :
	make prepare
	docker compose -f ${DOCKER_COMPOSE_FILE} up -d --build

prepare :
	@if [ ! -d "${DATA_PATH}/wordpress-data" ]; then \
		mkdir -p ${DATA_PATH}/wordpress-data; \
	fi
	@if [ ! -d "${DATA_PATH}/mariadb-data" ]; then \
		mkdir -p ${DATA_PATH}/mariadb-data; \
	fi

start :
	docker compose -f ${DOCKER_COMPOSE_FILE} start

stop :
	docker compose -f ${DOCKER_COMPOSE_FILE} stop

down :
	docker compose -f ${DOCKER_COMPOSE_FILE} down

clean :
	-docker container stop ${CONTAINERS}
	-docker container rm ${CONTAINERS}
	-docker image rm ${IMAGES}
	-docker volume rm ${VOLUMES}
	-docker network rm ${NETWORKS}

fclean :
	-docker container stop ${CONTAINERS}
	-docker container rm ${CONTAINERS}
	-docker image rm ${IMAGES}
	-docker volume rm ${VOLUMES}
	-sudo rm -rf ${DB_DATAS}
	-docker network rm ${NETWORKS}
	-docker system prune -af

re :
	make fclean
	make up
