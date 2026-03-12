/* ------------------------------------------------------------
name: "test2"
Code generated with Faust 2.83.1 (https://faust.grame.fr)
Compilation options: -lang cpp -fpga-mem-th 4 -ct 1 -cn FaustDSP -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __FaustDSP_H__
#define  __FaustDSP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustDSP
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif


class FaustDSP : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fConst3;
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec2[2];
	float fConst4;
	float fConst5;
	float fConst6;
	FAUSTFLOAT fHslider3;
	float fRec5[2];
	float fConst7;
	float fRec3[2];
	FAUSTFLOAT fHslider4;
	float fRec1[3];
	
 public:
	FaustDSP() {
	}
	
	FaustDSP(const FaustDSP&) = default;
	
	virtual ~FaustDSP() = default;
	
	FaustDSP& operator=(const FaustDSP&) = default;
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -fpga-mem-th 4 -ct 1 -cn FaustDSP -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.3.0");
		m->declare("filename", "test2.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.7.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "test2");
		m->declare("options", "[midi:on][nvoices:8]");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/saw2ptr:author", "Julius O. Smith III");
		m->declare("oscillators.lib/saw2ptr:license", "STK-4.3");
		m->declare("oscillators.lib/version", "1.6.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("webaudio.lib/author", "GRAME");
		m->declare("webaudio.lib/copyright", "GRAME");
		m->declare("webaudio.lib/license", "LGPL with exception");
		m->declare("webaudio.lib/name", "Faust WebAudio Filters Library");
		m->declare("webaudio.lib/version", "1.1.0");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 2.0f / fConst0;
		fConst4 = std::max<float>(1.0f, 0.005f * fConst0);
		fConst5 = 1.0f / fConst4;
		fConst6 = 1.0f / std::max<float>(1.0f, 0.3f * fConst0);
		fConst7 = 1.0f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = static_cast<FAUSTFLOAT>(1e+03f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider2 = static_cast<FAUSTFLOAT>(1.0f);
		fButton0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider3 = static_cast<FAUSTFLOAT>(4.4e+02f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.8f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec2[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec1[l5] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual FaustDSP* clone() {
		return new FaustDSP(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("test2");
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Cutoff Hz", &fHslider0, FAUSTFLOAT(1e+03f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("Q / Resonance", &fHslider2, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.1f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("Detune cents", &fHslider1, FAUSTFLOAT(0.0f), FAUSTFLOAT(-1.2e+03f), FAUSTFLOAT(1.2e+03f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("freq", &fHslider3, FAUSTFLOAT(4.4e+02f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(2e+04f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("gain", &fHslider4, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst1 * static_cast<float>(fHslider0);
		float fSlow1 = fConst3 * std::pow(2.0f, 0.00083333335f * static_cast<float>(fHslider1));
		float fSlow2 = 0.5f * std::pow(1e+01f, -(0.05f * static_cast<float>(fHslider2)));
		float fSlow3 = static_cast<float>(fButton0);
		float fSlow4 = fConst1 * static_cast<float>(fHslider3);
		float fSlow5 = static_cast<float>(fHslider4);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = 3.1415927f * std::max<float>(0.01f, std::min<float>(fSlow1 * fRec0[0], 0.99f));
			float fTemp1 = fSlow2 * std::sin(fTemp0);
			float fTemp2 = fTemp1 + 1.0f;
			float fTemp3 = std::cos(fTemp0);
			fVec0[0] = fSlow3;
			iRec2[0] = (fSlow3 > fVec0[1]) + (fSlow3 <= fVec0[1]) * (iRec2[1] + (iRec2[1] > 0));
			float fTemp4 = static_cast<float>(iRec2[0]);
			fRec5[0] = fSlow4 + fConst2 * fRec5[1];
			float fTemp5 = std::max<float>(1.1920929e-07f, std::fabs(fRec5[0]));
			float fTemp6 = fRec3[1] + fConst7 * fTemp5;
			float fTemp7 = fTemp6 + -1.0f;
			int iTemp8 = fTemp7 < 0.0f;
			fRec3[0] = ((iTemp8) ? fTemp6 : fTemp7);
			float fRec4 = ((iTemp8) ? fTemp6 : fTemp6 + (1.0f - fConst0 / fTemp5) * fTemp7);
			fRec1[0] = fSlow5 * (2.0f * fRec4 + -1.0f) * std::max<float>(0.0f, std::min<float>(fConst5 * fTemp4, fConst6 * (fConst4 - fTemp4) + 1.0f)) - (fRec1[2] * (1.0f - fTemp1) - 2.0f * fRec1[1] * fTemp3) / fTemp2;
			float fTemp9 = (1.0f - fTemp3) * (fRec1[1] + 0.5f * fRec1[0] + 0.5f * fRec1[2]) / fTemp2;
			output0[i0] = static_cast<FAUSTFLOAT>(fTemp9);
			output1[i0] = static_cast<FAUSTFLOAT>(fTemp9);
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			iRec2[1] = iRec2[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
