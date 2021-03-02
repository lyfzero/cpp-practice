#include<iostream>
#include<string>
class Sales_item {

    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item);
    friend bool operator<(const Sales_item&, const Sales_item);
    friend bool operator==(const Sales_item&, const Sales_item&);
public:
    Sales_item(): units_sold(0), revenue(0.0) {}
    Sales_item(const std::string &book): bookNo(book), units_sold(0), revenue(0.0) {}
    Sales_item(std::istream &is) {is >> *this;}
public:
    Sales_item& operator+=(const Sales_item&);

    std::string isbn() const { return bookNo;}
    double avg_price() const;
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};