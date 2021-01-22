#include "SourceHighlighter.h"


SourceHighlighter::SourceHighlighter()
{
	const QString consolePath = QCoreApplication::applicationDirPath() + "/highlight/highlight.exe";

	consoleApp.setProgram(consolePath);
}

QString SourceHighlighter::highlight(QString const& codeSnippet, QString const& lang) const
{

	QStringList arguments;
	arguments << "-S" << lang << defaultArguments;

	consoleApp.setArguments(arguments);
	consoleApp.start();
	consoleApp.waitForFinished();

	QString output(consoleApp.readAllStandardOutput());
	QString error(consoleApp.readAllStandardError());


	return output;
}