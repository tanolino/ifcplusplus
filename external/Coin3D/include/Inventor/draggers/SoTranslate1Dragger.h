#ifndef COIN_SOTRANSLATE1DRAGGER_H
#define COIN_SOTRANSLATE1DRAGGER_H

/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#include <Inventor/draggers/SoDragger.h>
#include <Inventor/tools/SbLazyPimplPtr.h>
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/fields/SoSFFloat.h>

class SoSensor;
class SoFieldSensor;
class SbLineProjector;
class SoTranslate1DraggerP;

class COIN_DLL_API SoTranslate1Dragger : public SoDragger {
  typedef SoDragger inherited;

  SO_KIT_HEADER(SoTranslate1Dragger);
  SO_KIT_CATALOG_ENTRY_HEADER(feedback);
  SO_KIT_CATALOG_ENTRY_HEADER(feedbackActive);
  SO_KIT_CATALOG_ENTRY_HEADER(feedbackSwitch);
  SO_KIT_CATALOG_ENTRY_HEADER(translator);
  SO_KIT_CATALOG_ENTRY_HEADER(translatorActive);
  SO_KIT_CATALOG_ENTRY_HEADER(translatorSwitch);

public:
static void initClass(void);
  SoTranslate1Dragger(void);

  SoSFVec3f translation;
  SoSFFloat minTranslation;
  SoSFFloat maxTranslation;

protected:
  virtual ~SoTranslate1Dragger(void);
  virtual SbBool setUpConnections(SbBool onoff, SbBool doitalways = FALSE);

  virtual void setMotionMatrix(const SbMatrix & matrix);

  static void startCB(void * f, SoDragger * d);
  static void motionCB(void * f, SoDragger * d);
  static void finishCB(void * f, SoDragger * d);
  static void fieldSensorCB(void * f, SoSensor * s);
  static void valueChangedCB(void * f, SoDragger * d);

  void dragStart(void);
  void drag(void);
  void dragFinish(void);

  SoFieldSensor * fieldSensor;
  SbLineProjector * lineProj;

private:
  SbVec3f clampMatrix(SbMatrix & m) const;
  SbLazyPimplPtr<SoTranslate1DraggerP> pimpl;

  // NOT IMPLEMENTED:
  SoTranslate1Dragger(const SoTranslate1Dragger & rhs);
  SoTranslate1Dragger & operator = (const SoTranslate1Dragger & rhs);
}; // SoTranslate1Dragger

#endif // !COIN_SOTRANSLATE1DRAGGER_H
