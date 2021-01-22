#pragma once
#include <QTimer>
#include <QClipboard>
#include <QtWidgets/QMainWindow>
#include <QMimeData>

#include "ui_SourceFormatter.h"
#include "SourceHighlighter.h"
#include "SourceBeautifier.h"
#include "SourceLangDetector.h"
#include "OneNoteLib.h"

class SourceFormatter : public QMainWindow
{
    Q_OBJECT

public:
    enum CodeLanguage : uchar { CPP, JAVA, CSHARP, XML };

    SourceFormatter(QWidget *parent = Q_NULLPTR);


    CodeLanguage detectCodeLanguage(QString const& source);


public slots:

    void formatHeadLine(QString const& code);
    void switchClipboardWatcherState();


protected slots:
	void insertHtmlCodeIntoClipboard(QString const& htmlCode);
    void checkForNewCodeAndFormatIt();



private:
    QString makeCodeBeautiful(QString const& codeSnippet, const CodeLanguage lang);
    QString makeCodeHtmlHighlighted(QString const& codeSnippet, const CodeLanguage lang);

    QString const& getCodeLanguageStringForHighlights(const CodeLanguage lang);
    QString const& getCodeLanguageStringForAstyle(const CodeLanguage lang);


    Ui::SourceFormatterClass ui;

    QClipboard* clipboard = QApplication::clipboard();

    const SourceHighlighter highlighter;
    const SourceBeautifier beautifier;

    bool shouldWatchClipboard = true;

	const QHash<CodeLanguage, QString> astyleLangOptions = {
			{JAVA,	 "java"},
			{CPP,	 "c"},
			{CSHARP, "cs"}
	};

	const QHash<CodeLanguage, QString> highlighterLangOptions = {
			{JAVA, "java"},
			{CPP, "cpp"},
			{CSHARP, "csharp"},
			{XML, "xml"},
	};


};
