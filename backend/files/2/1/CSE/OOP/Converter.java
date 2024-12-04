// package Measure;

public class Converter {
    public float mmtom(float mm) {
        float m = (mm / 1000);
        return m;
    }

    public float cmtom(float cm) {
        float m = (cm / 100);
        return m;
    }

    public float mtokm(float m) {
        float km = (m / 1000);
        return km;
    }
}