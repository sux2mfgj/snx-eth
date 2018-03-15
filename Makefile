SRC := receiver.nsl snx_eth.nsl
TESTBENCH   := receiver_test
VERILOG := $(SRC:%.nsl=%.v)
VERILOG_SRC := $(VERILOG) $(TESTBENCH).v
NSL_DOCKER_IMAGE    := nsl_build
VVP := $(TESTBENCH).vvp
VCD := $(TESTBENCH).vcd

all:

build_docker:
	docker run -v "$(shell pwd):/work" $(NSL_DOCKER_IMAGE) make nsl2vl SRC=$(SRC)
	docker run -v "$(shell pwd):/work" $(NSL_DOCKER_IMAGE) make $(TESTBENCH).v

#build_docker_sim:
#	docker run -v "$(shell pwd):/work" $(NSL_DOCKER_IMAGE) make sim

vcd_docker:
	docker run -v $(shell pwd):/work $(NSL_DOCKER_IMAGE) make vcd

vvp_docker:
	docker run -v $(shell pwd):/work $(NSL_DOCKER_IMAGE) make vvp


nsl2vl: $(SRC)
	nsl2vl $(SRC) -o $(VERILOG)

$(TESTBENCH).v: $(TESTBENCH).nsl
	nsl2vl $< -o $@ -verisim2 -target $(TESTBENCH)

.PHONY: vvp
vvp: $(VVP)
$(VVP): $(VERILOG_SRC)
	iverilog -o $@ $^

.PHONY: vcd
vcd: $(VCD)
$(VCD): $(VVP)
	./$(VVP)

wave: $(VCD)
	gtkwave $<

clean:
	rm -f *.v *~ *.vcd *.vvp
