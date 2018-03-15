SRC := receiver.nsl
VERILOG := $(SRC:%.nsl=%.v)
NSL_DOCKER_IMAGE    := nsl_build

run_docker:
	docker run -v "$(shell pwd):/work" $(NSL_DOCKER_IMAGE) make nsl2vl SRC=$(SRC)

nsl2vl: $(SRC)
	nsl2vl $(SRC) -o $(VERILOG)

clean:
	rm -f *.v *~
