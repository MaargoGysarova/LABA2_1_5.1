#include "ESetErrors.h"

void InvalidIndex::print_error() const {
    cout <<"Index is uncorrected"<<endl;
}

void InvalidPoints::print_error() const {
    cout <<"Broken line hasn't this point"<<endl;
}

