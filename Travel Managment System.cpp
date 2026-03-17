#include <iostream>
#include<cstdlib>
#include <string>
#include<conio.h>

using namespace std;

const int MAX_ITEMS = 100;

// Data storage
string tourPackageNames[MAX_ITEMS];
string tourPackageDescriptions[MAX_ITEMS];
string tourPackageItineraries[MAX_ITEMS][10];
int tourPackageCount = 0;

int bookingIds[MAX_ITEMS];
string bookingTourNames[MAX_ITEMS];
string bookingCustomerNames[MAX_ITEMS];
string bookingStatuses[MAX_ITEMS];
int bookingCount = 0;

string accommodationHotelNames[MAX_ITEMS];
string accommodationRoomTypes[MAX_ITEMS];
int accommodationAvailabilities[MAX_ITEMS];
int accommodationCount = 0;

string transportationTypes[MAX_ITEMS];
string transportationDetails[MAX_ITEMS];
int transportationCount = 0;

int supportTicketIds[MAX_ITEMS];
string supportCustomerNames[MAX_ITEMS];
string supportMessages[MAX_ITEMS];
int supportTicketCount = 0;

int bookingIdCounter = 1;
int supportIdCounter = 1;

int main() {
    // Sample Data Initialization
    tourPackageNames[tourPackageCount] = "Beach Adventure";
    tourPackageDescriptions[tourPackageCount] = "A fun beach tour";
    tourPackageItineraries[tourPackageCount][0] = "Day 1: Arrival";
    tourPackageItineraries[tourPackageCount][1] = "Day 2: Beach Fun";
    tourPackageItineraries[tourPackageCount][2] = "Day 3: Departure";
    tourPackageCount++;

    accommodationHotelNames[accommodationCount] = "Seaside Hotel";
    accommodationRoomTypes[accommodationCount] = "Deluxe Room";
    accommodationAvailabilities[accommodationCount] = 10;
    accommodationCount++;

    transportationTypes[transportationCount] = "Car Rental";
    transportationDetails[transportationCount] = "Available for 3 days";
    transportationCount++;

    bool running = true;
    while (running) 
	{
        int choice;
        system ("cls");
        	 cout << "\t\t       * Travel With Us *\n" << endl;
    cout << "\t-------------------Main Menu----------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|                                           |" << endl;
    cout << "\t|Tours Management------------------------> 1|" << endl;
    cout << "\t|Bookings Management---------------------> 2|" << endl;
    cout << "\t|Accomodation Management-----------------> 3|" << endl;
    cout << "\t|Transportation--------------------------> 4|" << endl;
    cout << "\t|Customer Support------------------------> 5|" << endl;
    cout << "\t|Exit the Program------------------------> 0|" << endl;
    cout << "\t|                                           |" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
        cout <<endl<<"Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
		{
            // Manage Tour Packages
            int packageChoice;
            cout << "1. View Tour Packages"<<endl;
            cout << "2. Add Tour Package"<<endl;
            cout << "3. Customize Tour Package"<<endl;
            cout << "4. Delete Tour Package"<<endl;
            cout << "Enter your choice: ";
            cin >> packageChoice;

            if (packageChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < tourPackageCount; i++) 
				{
                    cout << "Name: " << tourPackageNames[i] << "\nDescription: " << tourPackageDescriptions[i] << "\nItinerary:\n";
                    for (int j = 0; j <10; j++) 
					{
                        cout << tourPackageItineraries[i][j] <<endl;
                    }
                    cout <<endl;
                }
                cout<<"Press Enter to go to main menu";
                getch();
            } 
			else if (packageChoice == 2) 
			{
				system("cls");
                if (tourPackageCount < MAX_ITEMS) 
				{
                    cout << "Enter tour name: ";
                    cin.ignore();
                    getline(cin, tourPackageNames[tourPackageCount]);
                    cout << "Enter tour description: ";
                    getline(cin, tourPackageDescriptions[tourPackageCount]);
                    cout << "Enter number of itinerary days: ";
                    int days;
                    cin >> days;
                    while(cin.fail())
                    {
                    	cin.clear();
                    	cin.ignore(1000000,'\n');
                    	cout<<"Enter a valid number: ";
                    	cin>>days;
					}
					cin.ignore();
                    for (int i = 0; i < days; i++) 
					{
                        cout << "Enter itinerary for day " << i + 1 << ": ";
                        getline(cin, tourPackageItineraries[tourPackageCount][i]);
                    }
                    tourPackageCount++;
                    cout<<endl<<"Tour has been added succefully!"<<endl<<"Press Enter to go to main menu";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more tour packages. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to main menu";
                    getch();
                }
            }
            else if(packageChoice == 3)
            {
            	int customize;
            	cout<<"Enter the index of the tour you want to customize: ";
            	cin>>customize;
            	while(customize>=tourPackageCount)
            	{
            		cin.clear();
            		cin.ignore(10000,'\n');
            		cout<<"Index Not found: ";
            		cin>>customize;
				}
            	cout<<"Enter new tour name: ";
            	cin.ignore();
            	getline(cin, tourPackageNames[customize]);
            	cout<<endl<<"Enter tour description: ";
            	getline(cin, tourPackageDescriptions[customize]);
            	cout<<"Enter number of itinerary days: ";
            	int days;
            	cin>>days;
            	while(cin.fail())
            	{
            		cin.clear();
            		cin.ignore(100000,'\n');
            		cout<<"Enter a valid number: ";
					cin>>days; 
				}
            	cin.ignore();
//            	for(int i=0;i<10;i++)
//            	{
//            		tourPackageItineraries[customize][i]="";
//				}
            	for(int i=0;i<days;i++)
            	{
            		cout<<"Enter itinerary for day "<<i+1<<": ";
            		getline(cin, tourPackageItineraries[customize][i]);
				}
				cout<<endl<<"Tour has been customized successfully!"<<endl<<"Press Enter to go to menu";
				getch();
			}
			else if(packageChoice == 4 )
			{
				cout<<"Enter the index of the tour you want to delete: ";
				int del;
				cin>>del;
				while(del>=tourPackageCount)
				{
					cin.clear();
					cin.ignore(100000,'\n');
					cout<<"Index Not Found: ";
					cin>>del;
				}
				tourPackageNames[del]=tourPackageNames[del+1];
				tourPackageDescriptions[del]=tourPackageDescriptions[del+1];
				for(int i=del;i<tourPackageCount-1;i++)
				{
					tourPackageNames[i]=tourPackageNames[i+1];
				    tourPackageDescriptions[i]=tourPackageDescriptions[i+1];
				    for(int j=0;j<10;j++)
				    {
				    	tourPackageItineraries[i][j]=tourPackageItineraries[i+1][j];
					}
					
				}
				tourPackageCount--;
				cout<<endl<<"Tour has been deleted successfully!"<<endl<<"Press Enter to go to menu";
				getch();
			}
        } 
		else if (choice == 2) 
		{
            // Manage Bookings
            int bookingChoice;
            cout << "1. View Bookings"<<endl;
            cout << "2. Add Booking"<<endl;
            cout << "Enter your choice: ";
            cin >> bookingChoice;

            if (bookingChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < bookingCount; ++i) 
				{
                    cout << "Booking ID: " << bookingIds[i] << "\nTour: " << bookingTourNames[i] << "\nCustomer: " << bookingCustomerNames[i] << "\nStatus: " << bookingStatuses[i] <<endl<<endl;
                }
                cout<<"Press Enter to go to main menu";
                getch();
            } 
			else if (bookingChoice == 2) 
			{
				system("cls");
                if (bookingCount < MAX_ITEMS) 
				{
                    bookingIds[bookingCount] = bookingIdCounter++;
                    cout << "Enter tour name: ";
                    cin.ignore();
                    getline(cin, bookingTourNames[bookingCount]);
                    cout << "Enter customer name: ";
                    getline(cin, bookingCustomerNames[bookingCount]);
                    bookingStatuses[bookingCount] = "Confirmed";
                    bookingCount++;
                    cout<<"Tour has been booked for the customer successfully!"<<endl<<"Press Enter to go to menu";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more bookings. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to menu";
                    getch();
                }
            }
        } 
		else if (choice == 3) 
		{
            // Manage Accommodations
            int accommodationChoice;
            cout << "1. View Accommodations"<<endl;
            cout << "2. Add Accommodation"<<endl;
            cout << "Enter your choice: ";
            cin >> accommodationChoice;

            if (accommodationChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < accommodationCount; ++i) 
				{
                    cout << "Hotel: " << accommodationHotelNames[i] << "\nRoom: " << accommodationRoomTypes[i] << "\nAvailability: " << accommodationAvailabilities[i] <<endl<<endl;
                }
                cout<<"Press Enter to go to menu";
                getch();
            } 
			else if (accommodationChoice == 2) 
			{
				system("cls");
                if (accommodationCount < MAX_ITEMS) 
				{
                    cout << "Enter hotel name: ";
                    cin.ignore();
                    getline(cin, accommodationHotelNames[accommodationCount]);
                    cout << "Enter room type: ";
                    getline(cin, accommodationRoomTypes[accommodationCount]);
                    cout << "Enter availability: ";
                    cin >> accommodationAvailabilities[accommodationCount];
                    accommodationCount++;
                    cout<<endl<<"Accomodation has been added successfully!"<<endl<<"Press Enter to go to menu";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more accommodations. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to menu";
                    getch();
                }
            }
        } 
		else if (choice == 4) 
		{
            // Manage Transportation
            int transportChoice;
            cout << "1. View Transportation Options"<<endl;
            cout << "2. Add Transportation Option"<<endl;
            cout << "Enter your choice: ";
            cin >> transportChoice;

            if (transportChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < transportationCount; ++i) 
				{
                    cout << "Type: " << transportationTypes[i] << "\nDetails: " << transportationDetails[i] <<endl<<endl;
                }
                cout<<"Press Enter to go to menu";
                getch();
            } 
			else if (transportChoice == 2) 
			{
				system("cls");
                if (transportationCount < MAX_ITEMS) 
				{
                    cout << "Enter transport type: ";
                    cin.ignore();
                    getline(cin, transportationTypes[transportationCount]);
                    cout << "Enter details: ";
                    getline(cin, transportationDetails[transportationCount]);
                    transportationCount++;
                    cout<<"Transport has been added successfully!";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more transportation options. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to menu";
                    getch();
                }
            }
        } 
		else if (choice == 5) 
		{
            // Customer Support
            int supportChoice;
            cout << "1. View Support Tickets"<<endl;
            cout << "2. Add Support Ticket"<<endl;
            cout << "Enter your choice: ";
            cin >> supportChoice;

            if (supportChoice == 1) 
			{
				system("cls");
                for (int i = 0; i < supportTicketCount; ++i) 
				{
                    cout << "Support ID: " << supportTicketIds[i] << "\nCustomer: " << supportCustomerNames[i] << "\nMessage: " << supportMessages[i] <<endl<<endl;
                }
                cout<<"Press Enter to go to menu";
                getch();
            } 
			else if (supportChoice == 2) 
			{
				system("cls");
                if (supportTicketCount < MAX_ITEMS) 
				{
                    supportTicketIds[supportTicketCount] = supportIdCounter++;
                    cout << "Enter customer name: ";
                    cin.ignore();
                    getline(cin, supportCustomerNames[supportTicketCount]);
                    cout << "Enter message: ";
                    getline(cin, supportMessages[supportTicketCount]);
                    supportTicketCount++;
                    cout<<"Customer Support has been added successfully!"<<endl<<"Press Enter to go to menu";
                    getch();
                } 
				else 
				{
                    cout << "Cannot add more support tickets. Storage limit reached."<<endl;
                    cout<<"Press Enter to go to menu";
                    getch();
                }
            }
        } 
		else if (choice == 0) 
		{
			system("cls");
			cout<<"\n\n\n\n\n\t\t\t\tExiting the Program....";
            running = false;
        } 
		else {
            cout << "Invalid choice, please try again."<<endl<<"Press Enter to go to menu";
            getch();
        }
    }

    return 0;
}

