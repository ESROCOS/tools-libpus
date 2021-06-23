KAZOO?=kazoo
# Here you can specify folders containing external code you want to
# compile and link for a specific partition.
# Use upper case for the partition name:


export X86_PARTITION_EXTERNAL_SOURCE_PATH = $(AUTOPROJ_CURRENT_ROOT)/install/include/pus:$(AUTOPROJ_CURRENT_ROOT)/install/include/pus/mission/test_01:$(AUTOPROJ_CURRENT_ROOT)/install/include/pus/mission/test_01/mpy:/usr/include/python3.6m

export X86_PARTITION_USER_LDFLAGS = -L$(AUTOPROJ_CURRENT_ROOT)/install/lib \
	-lesrocos_pus_core_test_01 \
	-lesrocos_pus_test_01 -lpython3.6m
	


all:	c

c:	work/glue_built
	$(MAKE) -C work

skeletons:
	$(MAKE) work/skeletons_built

work/skeletons_built:	InterfaceView.aadl DataView.aadl
	$(KAZOO) --gw -o work
	$(MAKE) -C work dataview
	touch $@

work/glue_built:	InterfaceView.aadl DeploymentView.aadl DataView.aadl
	$(KAZOO) -p --glue --gw -o work
	touch $@

clean:
	rm -rf work/build
	rm -f work/glue_built work/skeletons_built
	find work -type d -name "wrappers" -exec rm -rf {} +
	find work -type d -name "*_GUI" -exec rm -rf {} +

.PHONY: clean skeletons c

see_options:
	echo $(X86_PARTITION_EXTERNAL_SOURCE_PATH)
	echo $(X86_PARTITION_USER_LDFLAGS)


