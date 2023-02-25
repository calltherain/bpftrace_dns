#!/bin/bash

sudo nerdctl run -ti -v /usr/src:/usr/src:ro \
       -v /lib/modules/:/lib/modules:ro \
       -v /sys/kernel/debug/:/sys/kernel/debug:rw \
		-v `pwd`:/src \
       --net=host --pid=host --privileged \
       quay.io/iovisor/bpftrace:latest \
		bash
