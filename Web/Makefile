CC=g++
STD=-std=c++11
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

all: $(BUILD_DIR) goodeats.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/main.o: CppCodes/main.cpp server/server.hpp CppCodes/MainObjects/InterFace.hpp
	$(CC) $(CF) -c CppCodes/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/InterFace.o: CppCodes/InterFace.cpp CppCodes/MainObjects/InterFace.hpp
	$(CC) $(CF) -c CppCodes/InterFace.cpp -o $(BUILD_DIR)/InterFace.o

$(BUILD_DIR)/serverLists.o: CppCodes/serverLists.cpp CppCodes/MainObjects/InterFace.hpp
	$(CC) $(CF) -c CppCodes/serverLists.cpp -o $(BUILD_DIR)/serverLists.o

$(BUILD_DIR)/Put.o: CppCodes/Put.cpp CppCodes/MainObjects/InterFace.hpp CppCodes/SideFuncs/AllFuncs.hpp
	$(CC) $(CF) -c CppCodes/Put.cpp -o $(BUILD_DIR)/Put.o 

$(BUILD_DIR)/Post.o: CppCodes/Post.cpp CppCodes/MainObjects/InterFace.hpp
	$(CC) $(CF) -c CppCodes/Post.cpp -o $(BUILD_DIR)/Post.o

$(BUILD_DIR)/Get.o: CppCodes/Get.cpp CppCodes/MainObjects/InterFace.hpp
	$(CC) $(CF) -c CppCodes/Get.cpp -o $(BUILD_DIR)/Get.o

$(BUILD_DIR)/Delete.o: CppCodes/Delete.cpp CppCodes/MainObjects/InterFace.hpp
	$(CC) $(CF) -c CppCodes/Delete.cpp -o $(BUILD_DIR)/Delete.o

$(BUILD_DIR)/myServer.o: CppCodes/myServer.cpp CppCodes/MainObjects/myServer.hpp
	$(CC) $(CF) -c CppCodes/myServer.cpp -o $(BUILD_DIR)/myServer.o

$(BUILD_DIR)/Alerts.o: CppCodes/Alerts.cpp CppCodes/Errors/AllErrors.hpp
	$(CC) $(CF) -c CppCodes/Alerts.cpp -o $(BUILD_DIR)/Alerts.o

$(BUILD_DIR)/Recipe.o: CppCodes/Recipe.cpp CppCodes/Errors/AllErrors.hpp CppCodes/MainObjects/Recipe.hpp CppCodes/SideFuncs/AllFuncs.hpp CppCodes/MainObjects/Rating.hpp
	$(CC) $(CF) -c CppCodes/Recipe.cpp -o $(BUILD_DIR)/Recipe.o

$(BUILD_DIR)/Shelve.o: CppCodes/Shelve.cpp CppCodes/Errors/AllErrors.hpp CppCodes/MainObjects/Recipe.hpp CppCodes/Members/AllMembers.hpp CppCodes/MainObjects/Shelve.hpp
	$(CC) $(CF) -c CppCodes/Shelve.cpp -o $(BUILD_DIR)/Shelve.o

$(BUILD_DIR)/User.o: CppCodes/User.cpp CppCodes/Errors/AllErrors.hpp CppCodes/MainObjects/Recipe.hpp CppCodes/Members/AllMembers.hpp CppCodes/MainObjects/Shelve.hpp
	$(CC) $(CF) -c CppCodes/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Chef.o: CppCodes/Chef.cpp CppCodes/Errors/AllErrors.hpp CppCodes/MainObjects/Recipe.hpp CppCodes/Members/AllMembers.hpp
	$(CC) $(CF) -c CppCodes/Chef.cpp -o $(BUILD_DIR)/Chef.o

$(BUILD_DIR)/Member.o: CppCodes/Member.cpp CppCodes/Errors/AllErrors.hpp CppCodes/MainObjects/Member.hpp
	$(CC) $(CF) -c CppCodes/Member.cpp -o $(BUILD_DIR)/Member.o

$(BUILD_DIR)/SideFuncs.o: CppCodes/SideFuncs.cpp  CppCodes/Errors/AllErrors.hpp CppCodes/MainObjects/Recipe.hpp CppCodes/SideFuncs/AllFuncs.hpp CppCodes/Members/AllMembers.hpp CppCodes/Operators/OtherOperators.hpp
	$(CC) $(CF) -c CppCodes/SideFuncs.cpp -o $(BUILD_DIR)/SideFuncs.o

$(BUILD_DIR)/ControlRoom.o: CppCodes/ControlRoom.cpp  CppCodes/MainObjects/ControlRoom.hpp
	$(CC) $(CF) -c CppCodes/ControlRoom.cpp -o $(BUILD_DIR)/ControlRoom.o

$(BUILD_DIR)/Filters.o: CppCodes/Filters.cpp CppCodes/SideFuncs/SearchFuncs.hpp CppCodes/Errors/AllErrors.hpp CppCodes/Filters/AllFilters.hpp
	$(CC) $(CF) -c CppCodes/Filters.cpp -o $(BUILD_DIR)/Filters.o

goodeats.out:  $(BUILD_DIR)/main.o $(BUILD_DIR)/Filters.o $(BUILD_DIR)/Shelve.o $(BUILD_DIR)/ControlRoom.o $(BUILD_DIR)/SideFuncs.o $(BUILD_DIR)/Member.o $(BUILD_DIR)/Recipe.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Chef.o  $(BUILD_DIR)/Alerts.o $(BUILD_DIR)/myServer.o $(BUILD_DIR)/Put.o $(BUILD_DIR)/Delete.o $(BUILD_DIR)/Post.o $(BUILD_DIR)/Get.o $(BUILD_DIR)/serverLists.o  $(BUILD_DIR)/InterFace.o  $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o
	$(CC) $(CF) $(BUILD_DIR)/main.o $(BUILD_DIR)/Filters.o $(BUILD_DIR)/Shelve.o $(BUILD_DIR)/SideFuncs.o $(BUILD_DIR)/Member.o $(BUILD_DIR)/Recipe.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Chef.o  $(BUILD_DIR)/Alerts.o $(BUILD_DIR)/myServer.o $(BUILD_DIR)/Put.o $(BUILD_DIR)/Delete.o $(BUILD_DIR)/Post.o $(BUILD_DIR)/Get.o $(BUILD_DIR)/serverLists.o  $(BUILD_DIR)/InterFace.o  $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o  -o goodeats.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null
