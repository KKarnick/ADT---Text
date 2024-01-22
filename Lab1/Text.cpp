
//K. Karnick
//ad1797

#include "Text.h"

Text::Text(const char* charSeq) {
	bufferSize = strlen(charSeq) + 1; //set bufferSize var    add 1 for null 
	buffer = new char[bufferSize];  //allocate space for new char sequence of given length + null term. allotment
	strcpy_s(buffer, bufferSize, charSeq);  //copy chars from charSeq into buffer
}

Text::Text(const Text& other) {
	bufferSize = other.bufferSize;  //set bufferSize to Text from which to be copied
	buffer = new char[bufferSize];  //allocate space for new char seqence (deep copy of other's char seq)
	strcpy_s(buffer, bufferSize, other.buffer);  //copy buffer contents from other to new Text instance
}

void Text::operator = (const Text& other) {
	//used to set one Text obj equal to another (deep copy)		

		 // FIRST, ensure other isn't the SAME object (wasted time/space!)
	if (this != &other) {

		//do NOT need to check bufferSize of other (a max value), just the length of what's IN it
		if (other.getLength() >= bufferSize) {   //check to ensure space is adequate
			delete buffer;   //deallocate anything currently in buffer
			bufferSize = other.getLength() + 1;  //reallocate space for copy (+1 for null terminator)
			buffer = new char[bufferSize];  //set buffer equal to new size
		}
		//strcpy gives warnings by compiler, but told to use
		strcpy_s(buffer, bufferSize, other.buffer);   //copy other's buffer contents into current instance's buffer
	}
}

Text::~Text() {  //release dynamic memory
	delete[] buffer;  //deallocate the entire array pointed to by buffer pointer
}

int Text::getLength() const {
	//strlen will read number of chars until null term located
	return strlen(buffer); //return size of contents in buffer WITHOUT null term. (constructor adds 1 for bufferSize)
}

char Text::operator [] (int n) const {
	//ensure index is within bounds and return element at location n if so
	if (n >= 0 && n <= getLength()) {  //could also use strlen(buffer), but then why have getLength if not to use?
		return buffer[n];
	}
	else
		return '\0';  //same as null seq. term
}

void Text::clear() {
	//set first element in char seq to null terminating char. to denote no contents (no change to bufferSize, just content)
	buffer[0] = '\0';
}

void Text::showStructure() const {
	//could also set parameters to show null char (includes changing to i < getLength() + 1 ) or could use enhanced while loop
	for (int i = 0; i < getLength(); ++i)
		cout << buffer[i] << " ";
	cout << endl;
}

Text Text::toUpper() const {
	Text temp(buffer);  //create temp obj and pass contents of curr buffer instance as parameter 
	for (int i = 0; i < temp.getLength(); i++) {  //loop through new buffer (temp)
		if (isalpha(temp.buffer[i])) {      //check if it is alpha
			int c = toupper(temp.buffer[i]);   //if isalpha(), change element at i in temp's buffer to upper case 
			temp.buffer[i] = char(c);    //cast ASCII upper back to char and update temp's buffer
		}
	}
	return temp;   //return temp for output, keeping original char sequence unchanged
}

Text Text::toLower() const {
	Text temp(buffer);  //create temp obj and pass contents of curr buffer instance as parameter 
	for (int i = 0; i < temp.getLength(); i++) {  //loop through new buffer (temp)
		if (isalpha(temp.buffer[i])) {
			int c = tolower(temp.buffer[i]);   //if isalpha(), change element at i in temp's buffer to lower case 
			temp.buffer[i] = char(c);    //cast ASCII lower back to char and update temp's buffer
		}
	}
	return temp;   //return temp for output, keeping original char sequence unchanged
}

bool Text::operator == (const Text& other) const {
	//use string compare function to compare strings in both buffers element by element
	return strcmp(buffer, other.buffer) == 0;
}

bool Text::operator <  (const Text& other) const {
	//use string compare function to compare strings in both buffers element by element
	return strcmp(buffer, other.buffer) < 0;

}

bool Text::operator >  (const Text& other) const {
	//use string compare function to compare strings in both buffers element by element
	return strcmp(buffer, other.buffer) > 0;
}


