#pragma once
#include "Annotation.h"



class AnnotationFactory
{

public:
	Annotation* regularText(Annotation::Data const& anno, QString const& text) const
	{
		return new TextSegment(anno, text);
	}

// 	std::unique_ptr<Annotation> headline() const
// 	{
// 		return std::make_unique<Headline>();
// 	}
// 
	Annotation* figure(Annotation::Data const& anno, QString const& filePath, QSize const& imageSize ) const
	{
		return new Figure(anno, filePath, imageSize);
	}
// 
// 	std::unique_ptr<Annotation> sourceCode() const
// 	{
// 		return std::make_unique<SourceCode>();
// 	}

	static AnnotationFactory const& factory()
	{
		static AnnotationFactory factory;
		return factory;
	}


private:



};

