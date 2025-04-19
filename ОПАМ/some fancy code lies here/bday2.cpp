#include <iostream>

bool checkIfLeapYear(int year) {
    ++year;
    return ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main()
{
    int daysInSpecificMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    int bday = 17, bmonth = 3, currday = 24, currmonth = 4, curryear = 2024;
    int daysPassedBD = bday, daysPassedCURR = currday, DAYSINYEAR = 365;
    
    if( checkIfLeapYear(curryear) ) {
        daysInSpecificMonth[1] = 29;
        DAYSINYEAR++;
    } else daysInSpecificMonth[1] = 28;
    
    for(int i=0; i<bmonth-1; i++) {
        // тобто рахуємо ПОВНІ дні січня, лютого та дні місяця народження (31 + 28 + 17) 
        daysPassedBD += daysInSpecificMonth[i];
    }
    
    for(int j=0; j<currmonth-1; j++) {
        // тобто рахуємо ПОВНІ дні січ, лют, бер та минувші дні кві (31 + 28 + 31 + 24) 
        daysPassedCURR += daysInSpecificMonth[j];
    }
    std::cout<<daysPassedBD<<std::endl;
    std::cout<<daysPassedCURR<<std::endl;
    std::cout<<DAYSINYEAR - (daysPassedCURR - daysPassedBD);

    return 0;
}
