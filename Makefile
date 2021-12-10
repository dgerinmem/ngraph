.PHONY: clean build

PWD = $(shell pwd)
#DOCKER_IMG = hdgerin/cmake-fullpython:xenial-latest
DOCKER_IMG = ghcr.io/dgerinmem/dhub:release

build_docker:
	docker pull ${DOCKER_IMG}

# build_ngraph_docker:
#     docker build  -f   contrib/docker/Dockerfile.ngraph.ubuntu1604 -t ttiti contrib/docker/

build: ${SRC}
	docker run -v ${PWD}:/work ${DOCKER_IMG} bash -c "mkdir -p /work/build && cd /work/build && cmake  /work/ && make"

test: FORCE
	./build/test/unit-test
	
FORCE: ;

.DEFAULT_GOAL := build
