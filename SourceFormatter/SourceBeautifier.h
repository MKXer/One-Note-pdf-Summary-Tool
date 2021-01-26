#pragma once
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>


class SourceBeautifier
{

public:
	explicit SourceBeautifier();
	const QString makeCodeBeautiful(QString const& codeSnippet, QString const& lang) const;

private:
	const QString readCodeFromFile() const;
	void saveCodeToFile(QString const& codeSnippet) const;

	mutable QProcess consoleApp;

	const QString appDirPath   = QCoreApplication::applicationDirPath();
	const QString tempFilePath = appDirPath + "/source.txt";
	const QString consolePath  = appDirPath + "/astyle/AStyle.exe";
};

