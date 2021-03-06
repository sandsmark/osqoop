/*

Osqoop, an open source software oscilloscope.
Copyright (C) 2006--2009 Stephane Magnenat <stephane at magnenat dot net>
http://stephane.magnenat.net
Laboratory of Digital Systems
http://www.eig.ch/fr/laboratoires/systemes-numeriques/
Engineering School of Geneva
http://hepia.hesge.ch/
See authors file in source distribution for details about contributors



This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#ifndef __PROCESSING_IIR_2ND_ORDER_FILTER
#define __PROCESSING_IIR_2ND_ORDER_FILTER

#include <ProcessingPlugin.h>
#include <QObject>

class QWidget;
class QLabel;
class QSliderDoubleDisplay;
class IIRFilter;

//! Description of a IIR 2nd order filter with user defined coefficient
class IIR2ndOrderFilterDescription : public QObject, public ProcessingPluginDescription
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "ch.eig.lsn.Oscilloscope.ProcessingPluginDescription/1.0" FILE "iir2ndorder.json")
	Q_INTERFACES(ProcessingPluginDescription)

public:
	QString systemName() const;
	QString name() const;
	QString description() const;
	unsigned inputCount() const;
	unsigned outputCount() const;
	ProcessingPlugin *create(const DataSource *dataSource) const;
};

//! IIR 2nd order filter with user defined coefficient
class IIR2ndOrderFilter : public QObject, public ProcessingPlugin
{
	Q_OBJECT
    
public:
	QWidget *createGUI(void);
	void processData(const std::valarray<signed short *> &inputs, const std::valarray<signed short *> &outputs, unsigned sampleCount);
	void terminate(void) { deleteLater(); }
	void load(QTextStream *stream);
	void save(QTextStream *stream);

protected:
	~IIR2ndOrderFilter();

private slots:
	void b0Changed(double);
	void b1Changed(double);
	void b2Changed(double);
	void a1Changed(double);
	void a2Changed(double);

private:
	friend class IIR2ndOrderFilterDescription;
	IIR2ndOrderFilter(const ProcessingPluginDescription *description);
	
private:
	IIRFilter *filter;
	double b[3];
	double a[3];
};

#endif
/* vim: set ts=8 sw=8 tw=0 noexpandtab cindent softtabstop=8 :*/
