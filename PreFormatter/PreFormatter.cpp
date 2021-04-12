#include "PreFormatter.h"
#include "AnnotationExtractor.h"
#include "SummaryCreator.h"
#include <QMessageBox>

PreFormatter::PreFormatter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	connect(ui.OPEN_FILE_BUTTON, &QPushButton::clicked, this, &PreFormatter::extract);
}

void PreFormatter::extract()
{
	auto figurePath = QApplication::applicationDirPath() + "/figures/";
	auto filePath  = openFileDialog();
	//QApplication::applicationDirPath() + "/test.pdf";
	auto document = Poppler::Document::load(filePath);


	if (!document || document->isLocked()) {
		delete document;

		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Could not load pdf File, it's not existing or locked!");
		messageBox.setFixedSize(500, 200);

	}
	else {
		qDebug() << figurePath;
		AnnotationExtractor extractor(document, figurePath);

		auto annoList = extractor.extract();

		SummaryCreator creator(annoList);

		QString html = creator.createOneNoteSummary();

		QMimeData* mimeData = new QMimeData;
		mimeData->setHtml(html);

		QApplication::clipboard()->setMimeData(mimeData);
	}

}



const QString PreFormatter::openFileDialog()
{
	return QFileDialog::getOpenFileName(this,
			tr("Open PDF file"), "/home/", tr("PDF File (*.pdf)"));
}

