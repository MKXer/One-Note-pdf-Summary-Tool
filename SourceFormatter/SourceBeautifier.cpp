#include "SourceBeautifier.h"

SourceBeautifier::SourceBeautifier()
{
	consoleApp.setProgram(consolePath);
}

QString SourceBeautifier::makeCodeBeautiful(QString const& codeSnippet, QString const& lang) const
{
	QStringList arguments;
	arguments << "--mode=" + lang << "--style=google" << tempFilePath;

	saveCodeToFile(codeSnippet);

	consoleApp.setArguments(arguments);
	consoleApp.start();
	consoleApp.waitForFinished();

	return readCodeFromFile();
}

QString SourceBeautifier::readCodeFromFile() const
{
	QFile file(tempFilePath);
	QString retn;

	if (file.open(QIODevice::ReadOnly | QFile::Text)) {
		QTextStream in(&file);
		retn = in.readAll();
	}

	return retn;
}

void SourceBeautifier::saveCodeToFile(QString const& codeSnippet) const
{
	QFile file(tempFilePath);

	if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
		QTextStream stream(&file);
		stream << codeSnippet;
	}
}
