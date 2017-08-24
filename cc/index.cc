#include <node.h>
#include "Mat.h"
#include "Point.h"
#include "Vec.h"
#include "Size.h"
#include "Rect.h"
#include "cvTypes/cvTypes.h"

#include "modules/io.h"
#include "modules/VideoCapture.h"
#include "modules/video/video.h"
#include "modules/photo.h"
#include "modules/calib3d/calib3d.h"
#include "modules/imgproc/imgproc.h"
#include "modules/features2d/features2d.h"
#include "modules/objdetect/objdetect.h"
#ifdef HAVE_XIMGPROC
#include "modules/ximgproc/ximgproc.h"
#endif // HAVE_XIMGPROC
#ifdef HAVE_XFEATURES2D
#include "modules/xfeatures2d/xfeatures2d.h"
#endif // HAVE_XFEATURES2D

void init(v8::Local<v8::Object> target) {
	v8::Local<v8::Object> xmodules = Nan::New<v8::Object>();
	Nan::Set(target, FF_V8STRING("xmodules"), xmodules);
  CvTypes::Init(target);
  Mat::Init(target);
	Point::Init(target);
	Vec::Init(target);
	Size::Init(target);
	Rect::Init(target);
  Io::Init(target);
	VideoCapture::Init(target);
	Video::Init(target);
  Photo::Init(target);
  Calib3d::Init(target);
  Imgproc::Init(target);
  Features2d::Init(target);
  Objdetect::Init(target);
#ifdef HAVE_XIMGPROC
	Nan::Set(xmodules, FF_V8STRING("ximgproc"), Nan::New(true));
	XImgproc::Init(target);
#endif // HAVE_XIMGPROC
#ifdef HAVE_XFEATURES2D
	Nan::Set(xmodules, FF_V8STRING("xfeatures2d"), Nan::New(true));
	XFeatures2d::Init(target);
#endif // HAVE_XFEATURES2D

};

NODE_MODULE(opencv4nodejs, init)
