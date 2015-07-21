#pragma once
#include <iostream>
#include <streambuf>
#include <string>

#include "qtextedit.h"
#include "qmutex.h"

class QDebugStream : public std::basic_streambuf<char>
{
public:
	QDebugStream( std::ostream &stream, QTextEdit* text_edit, QColor textColor ) : m_stream( stream )
	{
		TextColor = textColor;
		log_window = text_edit;
		m_old_buf = stream.rdbuf();
		stream.rdbuf( this );
	}
	~QDebugStream()
	{
		// output anything that is left
		if ( !m_string.empty() )
		{
			log_window->setTextColor( TextColor );
			log_window->append( m_string.c_str() );
		}
		m_stream.rdbuf( m_old_buf );
	}

protected:
	virtual int_type overflow( int_type v )
	{
		mutex.lock();
		if ( v == '\n' )
		{
			log_window->setTextColor( TextColor );
			log_window->append( m_string.c_str() );
			m_string.erase( m_string.begin(), m_string.end() );
		}
		else
			m_string += v;
		mutex.unlock();
		return v;
	}

	virtual std::streamsize xsputn( const char *p, std::streamsize n )
	{
		mutex.lock();
		m_string.append( p, p + n );

		int pos = 0;
		while ( pos != std::string::npos )
		{
			pos = m_string.find( '\n' );
			if ( pos != std::string::npos )
			{
				std::string tmp( m_string.begin(), m_string.begin() + pos );
				log_window->setTextColor( TextColor );
				log_window->append( tmp.c_str() );
				m_string.erase( m_string.begin(), m_string.begin() + pos + 1 );
			}
		}
		mutex.unlock();
		return n;
	}

private:
	std::ostream &m_stream;
	std::streambuf *m_old_buf;
	std::string m_string;
	QTextEdit* log_window;
	QColor TextColor;
	QMutex mutex;
};
