#include "SourceFormatter.h"

SourceFormatter::SourceFormatter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	connect(ui.CLIPBOARD_BTN, &QPushButton::clicked, this, &SourceFormatter::switchClipboardWatcherState);
	connect(clipboard, &QClipboard::dataChanged, this, &SourceFormatter::checkForNewCodeAndFormatIt);
}

void SourceFormatter::switchClipboardWatcherState()
{
	shouldWatchClipboard = !shouldWatchClipboard;
	ui.CLIPBOARD_BTN->setText(shouldWatchClipboard ? "Watch Clipboard ON" : "Watch Clipboard OFF");
}


QString SourceFormatter::makeCodeBeautiful(QString const& codeSnippet, const CodeLanguage lang)
{
	QString retn;

	if (lang != XML) {
		QString const& langString = getCodeLanguageStringForAstyle(lang);
		retn = beautifier.makeCodeBeautiful(codeSnippet, langString);
	}

	return retn;
}

QString SourceFormatter::makeCodeHtmlHighlighted(QString const& codeSnippet, const CodeLanguage lang)
{
	QString const& langString = getCodeLanguageStringForHighlights(lang);
		
	return highlighter.highlight(codeSnippet, langString);
}

void SourceFormatter::checkForNewCodeAndFormatIt()
{
	if (shouldWatchClipboard && !clipboard->ownsClipboard() ) {
		QString source = QApplication::clipboard()->text();

		if ( !source.isEmpty() ) {


			if (ui.OFF_RB->isChecked()) {
				const CodeLanguage lang = SourceFormatter::detectCodeLanguage(source);
	
				source = makeCodeBeautiful(source, lang);
				source = makeCodeHtmlHighlighted(source, lang);

				QMetaObject::invokeMethod(this, "insertHtmlCodeIntoClipboard", Qt::QueuedConnection, Q_ARG(QString const&, source));
			}
			else
				formatHeadLine(source);
		}
	}
}



void SourceFormatter::formatHeadLine(QString const& code)
{
	const auto factory = OneNoteLib::factory();
	std::unique_ptr<OneNoteTextElement> element;


	if (ui.H1_RB->isChecked()){
		element = std::move(factory.H1());
	}
	else if (ui.H2_RB->isChecked()){
		element = std::move(factory.H2());
	}
	else if (ui.H3_RB->isChecked()){
		element = std::move(factory.H3());
	}
	else if (ui.HT_RB->isChecked()) {
		element = std::move(factory.importantText());
	}


	if(element)
		QMetaObject::invokeMethod(this, "insertHtmlCodeIntoClipboard", Qt::QueuedConnection, Q_ARG(QString const&, element->getHtml(code)));
}

QString const& SourceFormatter::getCodeLanguageStringForHighlights( const CodeLanguage lang )
{
	return highlighterLangOptions[lang];
}

QString const& SourceFormatter::getCodeLanguageStringForAstyle( const CodeLanguage lang )
{
	return astyleLangOptions[lang];
}

SourceFormatter::CodeLanguage SourceFormatter::detectCodeLanguage(QString const& source)
{
	CodeLanguage retn = CPP;
		
	if ( ui.JAVA_CB->isChecked() && SourceLangDetector::isJava(source)) {
		retn = JAVA;
	}
	else  if (ui.CPP_CB->isChecked() &&  SourceLangDetector::isCpp(source)) {
		retn = CPP;
	}
	else  if (ui.CSHARP_CB->isChecked() &&  SourceLangDetector::isCSharp(source)) {
		retn = CSHARP;
	}
	else if (ui.XML_CB->isChecked() && SourceLangDetector::isXml(source)) {
		retn = XML;
	}

	return retn;
}

void SourceFormatter::insertHtmlCodeIntoClipboard(QString const& htmlCode)
{
	QMimeData* mimeData = new QMimeData;
	mimeData->setHtml(htmlCode);


	clipboard->setMimeData(mimeData);

}
