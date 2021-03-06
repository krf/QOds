/*
 * Copyright © 2014 f35f22fan@gmail.com
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef ODS_ATTRS_HPP_
#define ODS_ATTRS_HPP_

#include "global.hxx"
#include "err.hpp"
#include <QXmlStreamAttributes>

class QXmlStreamReader;
class QXmlStreamWriter;

namespace ods	{ // ods::
class Attr;
class Prefix;

class ODS_API Attrs
{
public:
	Attrs();
	virtual ~Attrs();
	
	void
	Add(ods::Attr *attr) { attrs_.append(attr); }
	
	void
	Add(ods::Prefix &prefix, const char *name);

	QVector<ods::Attr*>&
	attrs() { return attrs_; }
	
	ods::Attrs*
	Clone();

	void
	Delete(ods::Prefix &prefix, const char *name);
	
	ods::Attr*
	Get(ods::Prefix &prefix, const char *name);
	
	void
	Load(QXmlStreamReader &xml);
	
	void
	Write(QXmlStreamWriter &xml);
	
private:
	NO_ASSIGN_COPY_MOVE(Attrs);
	
	QVector<ods::Attr*>		attrs_;
};

} // ods::

#endif
