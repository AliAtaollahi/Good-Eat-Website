CC=g++ --std=c++11
EXE_FILE=goodeats.out
$(EXE_FILE) :  main.o SideFuncs.o Alerts.o  Chef.o ControlRoom.o Delete.o Filters.o Get.o Interface.o  Member.o Post.o Put.o ReadCommand.o Recipe.o Shelve.o User.o Supplier.o Ingredient.o Offer.o  Order.o
	$(CC) main.o SideFuncs.o Alerts.o  Chef.o ControlRoom.o Delete.o Filters.o Get.o Interface.o  Member.o Post.o Put.o ReadCommand.o Recipe.o Shelve.o User.o Ingredient.o Offer.o Supplier.o Order.o $(CCFLAGS) -o $(EXE_FILE)

main.o: main.cpp MainObjects/InterFace.hpp
	$(CC) -c main.cpp  -o main.o
	
Put.o: Put.cpp SideFuncs/AllFuncs.hpp MainObjects/ControlRoom.hpp
	$(CC) -c Put.cpp -o Put.o
	
User.o: User.cpp Errors/AllErrors.hpp Members/AllMembers.hpp MainObjects/Recipe.hpp MainObjects/Shelve.hpp
	$(CC) -c User.cpp -o User.o

ReadCommand.o: ReadCommand.cpp MainObjects/InterFace.hpp Lists/CommadsList.hpp
	$(CC) -c ReadCommand.cpp -o ReadCommand.o

Post.o: Post.cpp MainObjects/ControlRoom.hpp
	$(CC) -c Post.cpp -o Post.o

Delete.o: Delete.cpp MainObjects/ControlRoom.hpp
	$(CC) -c Delete.cpp -o Delete.o

Get.o: Get.cpp MainObjects/ControlRoom.hpp
	$(CC) -c Get.cpp -o Get.o

Alerts.o: Alerts.cpp Errors/AllErrors.hpp
	$(CC) -c Alerts.cpp -o Alerts.o

Chef.o: Chef.cpp Errors/AllErrors.hpp Members/AllMembers.hpp MainObjects/Recipe.hpp
	$(CC) -c Chef.cpp -o Chef.o

Supplier.o: Supplier.cpp Errors/AllErrors.hpp Members/AllMembers.hpp MainObjects/Recipe.hpp
	$(CC) -c Supplier.cpp -o Supplier.o

Recipe.o: Recipe.cpp Errors/AllErrors.hpp Members/AllMembers.hpp MainObjects/Recipe.hpp SideFuncs/AllFuncs.hpp MainObjects/Rating.hpp 
	$(CC) -c Recipe.cpp -o Recipe.o

SideFuncs.o: SideFuncs.cpp Errors/AllErrors.hpp Members/AllMembers.hpp MainObjects/Recipe.hpp SideFuncs/AllFuncs.hpp Operators/OtherOperators.hpp
	$(CC) -c SideFuncs.cpp -o SideFuncs.o

ControlRoom.o: ControlRoom.cpp MainObjects/ControlRoom.hpp Lists/AllLists.hpp
	$(CC) -c ControlRoom.cpp -o ControlRoom.o

InterFace.o: InterFace.cpp MainObjects/InterFace.hpp Lists/CommadsList.hpp
	$(CC) -c InterFace.cpp -o InterFace.o

Member.o: Member.cpp Errors/AllErrors.hpp MainObjects/Member.hpp
	$(CC) -c Member.cpp -o Member.o

Filters.o: Filters.cpp Filters/AllFilters.hpp Errors/AllErrors.hpp SideFuncs/SearchFuncs.hpp
	$(CC) -c Filters.cpp -o Filters.o

Shelve.o: Shelve.cpp Errors/AllErrors.hpp Members/AllMembers.hpp MainObjects/Recipe.hpp MainObjects/Shelve.hpp
	$(CC) -c Shelve.cpp -o Shelve.o

Ingredient.o: Ingredient.cpp MainObjects/Ingredient.hpp
	$(CC) -c Ingredient.cpp -o Ingredient.o

Offer.o: Offer.cpp MainObjects/Offer.hpp
	$(CC) -c Offer.cpp -o Offer.o

Order.o: Order.cpp MainObjects/Order.hpp
	$(CC) -c Order.cpp -o Order.o
clean:
	rm *.o $(EXE_FILE)