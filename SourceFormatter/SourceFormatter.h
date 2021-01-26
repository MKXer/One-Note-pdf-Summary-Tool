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


protected slots:
	void insertHtmlCodeIntoClipboard(QString const& htmlCode);
    void checkForNewCodeAndFormatIt();
	void formatHeadLineAndPutItIntoClipboard(QString const& text);
	void switchClipboardWatcherState();

private:
	const QString makeCodeBeautiful(QString const& codeSnippet, const CodeLanguage language) const;
	const QString makeCodeHtmlHighlighted(QString const& codeSnippet, const CodeLanguage language) const;

    QString const& getCodeLanguageStringForHighlights( CodeLanguage language) const;
    QString const& getCodeLanguageStringForAstyle( CodeLanguage language) const;

	CodeLanguage detectCodeLanguage(QString const& source);

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

	const QStringList BUTTON_LABEL { "Watch Clipboard ON", "Watch Clipboard OFF" };
};
