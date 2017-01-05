/*
 * CSViterator.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

/*
 *
 *   Read the column based data
 *
 *
 */


// based on  http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c#1120224
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class TEXTRow
{
public:
	std::string const& operator[](std::size_t index) const
	{
		return m_data[index];
	}

	std::size_t size() const
	{
		return m_data.size();
	}

	void readNextRow(std::istream& str)
	{
		std::string line;
		std::getline(str, line);

		std::stringstream lineStream(line);
		std::string cell;

		m_data.clear();
		while (std::getline(lineStream, cell, ' ')) {
			m_data.push_back(cell);
		}
		// This checks for a trailing comma with no data after it.
		if (!lineStream && cell.empty()) {
			// If there was a trailing comma then add an empty element.
			m_data.push_back("");
		}

	}

private:
	std::vector<std::string> m_data;

};

std::istream& operator>>(std::istream& str, TEXTRow& data)
{
	data.readNextRow(str);
	return str;
}

class TEXTIterator
{
public:
	typedef std::input_iterator_tag iterator_category;
	typedef TEXTRow value_type;
	typedef std::size_t difference_type;
	typedef TEXTRow* pointer;
	typedef TEXTRow& reference;

	TEXTIterator(std::istream& str) :
			m_str(str.good() ? &str : NULL)
	{
		++(*this);
	}

	TEXTIterator() : m_str(NULL) {}

	// Pre Increment
	TEXTIterator& operator++()
	{
		if (m_str) {
			if (!((*m_str) >> m_row)) {
				m_str = NULL;
			}
		}
		return *this;
	}

	// Post increment
	TEXTIterator operator++(int)
	{
		TEXTIterator tmp(*this);
		++(*this);
		return tmp;
	}

	TEXTRow const& operator*() const
	{
		return m_row;
	}

	TEXTRow const* operator->() const
	{
		return &m_row;
	}

	bool operator==(TEXTIterator const& rhs)
	{
		return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));
	}

	bool operator!=(TEXTIterator const& rhs)
	{
		return !((*this) == rhs);
	}
private:
	std::istream* m_str;
	TEXTRow m_row;
};

int main()
{
	std::ifstream simplefile("/home/songjiguo/workspace/interviewCode/src/cpputility/ReadData/simpledata.txt");
	for (TEXTIterator loop(simplefile); loop != TEXTIterator(); ++loop) {
		std::cout << std::stod((*loop)[0]) << " ";
		std::cout << std::stod((*loop)[1]) << "\n";
	}
}
