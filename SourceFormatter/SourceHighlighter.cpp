#include "SourceHighlighter.h"


SourceHighlighter::SourceHighlighter()
{
	const QString consolePath = QCoreApplication::applicationDirPath() + "/highlight/highlight.exe";

	consoleApp.setProgram(consolePath);
}

const QString SourceHighlighter::highlight(QString const& codeSnippet, QString const& lang) const
{
	QStringList arguments { "-S" , lang };

	arguments << defaultArguments;

	consoleApp.setArguments(arguments);
	consoleApp.start();
	consoleApp.waitForFinished();

	const QString output(consoleApp.readAllStandardOutput());
	const QString error(consoleApp.readAllStandardError());


	return output;
}