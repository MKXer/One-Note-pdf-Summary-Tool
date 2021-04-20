#include "SourceFormatter.h"

SourceFormatter::SourceFormatter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


	switchClipboardWatcherState();
	connect(ui.CLIPBOARD_BTN, &QPushButton::clicked,   this, &SourceFormatter::switchClipboardWatcherState);
	connect(clipboard,		 &QClipboard::dataChanged, this, &SourceFormatter::checkForNewCodeAndFormatIt );
}

void SourceFormatter::switchClipboardWatcherState()
{
	shouldWatchClipboard = !shouldWatchClipboard;
	ui.CLIPBOARD_BTN->setText( BUTTON_LABEL[shouldWatchClipboard] );
}

const QString SourceFormatter::makeCodeBeautiful(QString const& codeSnippet, const CodeLanguage language) const
{
	QString retn;

	if (language != XML) {
		QString const& languageString = getCodeLanguageStringForAstyle(language);
		retn = beautifier.makeCodeBeautiful(codeSnippet, languageString);
	}

	return retn;
}

const QString SourceFormatter::makeCodeHtmlHighlighted(QString const& codeSnippet, const CodeLanguage language) const
{
	QString const& languageString = getCodeLanguageStringForHighlights(language);
		
	return highlighter.highlight(codeSnippet, languageString);
}

void SourceFormatter::checkForNewCodeAndFormatIt()
{
	if (shouldWatchClipboard && !clipboard->ownsClipboard() ) {
		
		if (QString source = 
			QApplication::clipboard()->text(); !source.isEmpty() ) {

			if (ui.OFF_RB->isChecked()) {
				const CodeLanguage lang = SourceFormatter::detectCodeLanguage(source);
	
				source = makeCodeBeautiful(source, lang);
				source = makeCodeHtmlHighlighted(source, lang);

				QMetaObject::invokeMethod(this, "insertHtmlCodeIntoClipboard", Qt::QueuedConnection, Q_ARG(QString const&, source));
			}
			else
				formatHeadLineAndPutItIntoClipboard(source);
		}
	}
}

void SourceFormatter::formatHeadLineAndPutItIntoClipboard(QString const& text)
{
	const auto factory = OneNoteLib::factory();
	std::unique_ptr<OneNote::HtmlElement> element;

	if (ui.H1_RB->isChecked()){
		element = std::move(factory.h1(text));
	}
	else if (ui.H2_RB->isChecked()){
		element = std::move(factory.h2(text));
	}
	else if (ui.H3_RB->isChecked()){
		element = std::move(factory.h3(text));
	}
	else if (ui.HT_RB->isChecked()) {
		element = std::move(factory.importantText(text));
	}

	if(element)
		QMetaObject::invokeMethod(this, "insertHtmlCodeIntoClipboard", Qt::QueuedConnection, Q_ARG(QString const&, element->getHtml()));
}

QString const& SourceFormatter::getCodeLanguageStringForHighlights( CodeLanguage language) const
{
	return highlighterLangOptions[language];
}

QString const& SourceFormatter::getCodeLanguageStringForAstyle( CodeLanguage language) const
{
	return astyleLangOptions[language];
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
