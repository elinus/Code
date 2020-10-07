#ifndef __SALES_ITEM_H__
#define __SALES_ITEM_H__

#include <iostream>
#include <string>

class Sales_item {
    friend std::istream & operator>>(std::istream &, Sales_item &);
    friend std::ostream & operator<<(std::ostream &, const Sales_item &);
    friend bool operator<(const Sales_item &, const Sales_item &);
    friend bool operator==(const Sales_item &, const Sales_item &);
    public:
        Sales_item(): units_sold(0), revenue(0.0) {}
        Sales_item(const std::string & book):
            bookNo(book), units_sold(0), revenue(0.0) {}
        Sales_item(std::istream & is) {
            is >> *this;
        }
        std::string isbn() const {
            return bookNo;
        }
        double avg_price() const;
        Sales_item & operator+=(const Sales_item &);
    private:
        std::string bookNo;
        unsigned units_sold;
        double revenue;
};

double Sales_item::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    return 0.0;
}

std::istream & operator>>(std::istream & in, Sales_item & si) {
    double price;
    in >> si.bookNo >> si.units_sold >> price;
    if (in) 
        si.revenue = si.units_sold * price;
    else
        si = Sales_item();
    return in;
}

std::ostream & operator<<(std::ostream & out, const Sales_item & si) {
    out << si.isbn() << " " << si.units_sold << " " 
        << si.revenue << " " << si.avg_price();
    return out;
}

Sales_item & Sales_item::operator+=(const Sales_item & rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_item operator+(const Sales_item & lhs, const Sales_item & rhs) {
    Sales_item ret(lhs);
    ret += rhs;
    return ret;
}

bool operator==(const Sales_item & lhs, const Sales_item & rhs) {
    return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue && lhs.isbn() == rhs.isbn();
}

bool operator!=(const Sales_item & lhs, const Sales_item & rhs) {
    return !(lhs == rhs);
}

#endif /* __SALES_ITEM_H__ */
