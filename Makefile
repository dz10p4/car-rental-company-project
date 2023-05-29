compile:
	g++ CarRentalCompany.cpp CarRentalCompany_test.cpp Cars.cpp Client.cpp Employee.cpp RentalData.cpp Service.cpp Currency.cpp -o program

debug:
	g++ -g CarRentalCompany.cpp CarRentalCompany_test.cpp Cars.cpp Client.cpp Employee.cpp RentalData.cpp Service.cpp Currency.cpp -o program