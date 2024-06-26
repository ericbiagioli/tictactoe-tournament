all:
	# Generate the file all-headers-autogenerated.h, which 
	# includes all the .h files
	./generate_all_headers_h.sh > all_headers_autogenerated.h
	g++ players/*.cc judge.cc -I. -o tournament

unittests:
	g++ players/ericbiagioli_firstfree.cc \
		test_player_ericbiagioli_firstfree.cc	-I. \
		-o test_ericbiagioli_firstfree -l gtest

clean:
	rm tournament all_headers_autogenerated.h

