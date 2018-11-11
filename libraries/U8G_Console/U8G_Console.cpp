/* * * * * * * * * * * * * * * * * * * * * */

#include <U8G_Console.h>
#include <stdarg.h>

/* * * * * * * * * * * * * * * * * * * * * */

U8G_Console & U8G_Console::apply() {
	return scrollUp().update().draw().reset();
}

U8G_Console & U8G_Console::append(char value) {
  switch (value) {
    case '\r':
		return (*this); // ignore 
    case '\n':
		return apply();
    default: {
        if ( m_linePos >= cols() - 1 ) {
			apply();
        }
        m_lineBuf[m_linePos] = value;
        m_linePos++;
        m_lineBuf[m_linePos] = '\0';
        return (*this);
      }
  }
}

U8G_Console & U8G_Console::init(U8GLIB* u8g, const uint8_t * font) {
  m_u8g = u8g;
  m_u8g->setFont(font);
  m_u8g->setFontPosTop();

  const uint8_t h = (m_u8g->getHeight() / m_u8g->getFontLineSpacing());
  m_rows = (( h > ROW_MAX) ? ROW_MAX : h);

  const uint8_t w = (m_u8g->getWidth() / m_u8g->getStrWidth("m"));
  m_cols = (( w > (COL_MAX - 1)) ? (COL_MAX - 1) : w);

  return (*this);
}

U8G_Console & U8G_Console::clear() {
  for (uint8_t i = 0; i < rows(); i++ )
    for (uint8_t j = 0; j < cols(); j++ )
      m_data[i][j] = 0;
  return (*this);
}

U8G_Console & U8G_Console::draw() {
  m_u8g->firstPage();
  do {
    for (uint8_t i = 0, y = 1; i < rows(); i++ )
    {
      m_u8g->drawStr( 0, y, (char *)(m_data[i]));
      y += m_u8g->getFontLineSpacing();
    }
  } while ( m_u8g->nextPage() );
  return (*this);
}

U8G_Console & U8G_Console::update() {
  // Copy line buffer
  for (uint8_t j = 0; j < cols(); j++ )
    m_data[rows() - 1][j] = m_lineBuf[j];

  return (*this);
}

U8G_Console & U8G_Console::reset() {
  m_linePos = 0;
  m_lineBuf[m_linePos] = '\0';
  return (*this);
}

U8G_Console & U8G_Console::scrollUp() {
	for (uint8_t j = 0; j < cols(); j++ )
		for (uint8_t i = 0; i < (rows() - 1); i++ )
			m_data[i][j] = m_data[i + 1][j];
	return (*this);
}

/* * * * * * * * * * * * * * * * * * * * * */