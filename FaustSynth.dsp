import("stdfaust.lib");
wa = library("webaudio.lib");

declare options "[midi:on][nvoices:8]";

cutoff = hslider("[1] Cutoff Hz [style:knob]", 1000, 20, 20000, 1) : si.smoo;
q      = hslider("[2] Q / Resonance [style:knob]", 1, 0.1, 20, 0.01);
detune = hslider("[3] Detune cents [style:knob]", 0, -1200, 1200, 1);

freq  = hslider("freq", 440, 20, 20000, 0.01) : si.smoo;
gain  = hslider("gain", 0.8, 0, 1, 0.01);
gate  = button("gate");

osc = os.sawtooth(freq);
env = en.ar(0.005, 0.3, gate) * gain;

filtered = wa.lowpass2(cutoff, q, detune, osc * env);   // ← wersja jawna, bezpieczniejsza

process = filtered <: _,_;
