#include "math.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "camera/camera.h"
#include "scene/scene.h"
#include "screen/screen.h"
#include "utils/color/color.h"


static int width = 800;
// Die folgenden Kommentare beschreiben Datenstrukturen und Funktionen
// Die Datenstrukturen und Funktionen die weiter hinten im Text beschrieben sind,
// hängen höchstens von den vorhergehenden Datenstrukturen ab, aber nicht umgekehrt.


// Ein "Bildschirm", der das Setzen eines Pixels kapselt
// Der Bildschirm hat eine Auflösung (Breite x Höhe)
// Kann zur Ausgabe einer PPM-Datei verwendet werden oder
// mit SDL2 implementiert werden.


// Eine "Kamera", die von einem Augenpunkt aus in eine Richtung senkrecht auf ein Rechteck (das Bild) zeigt.
// Für das Rechteck muss die Auflösung oder alternativ die Pixelbreite und -höhe bekannt sein.
// Für ein Pixel mit Bildkoordinate kann ein Sehstrahl erzeugt werden.


// Für die "Farbe" benötigt man nicht unbedingt eine eigene Datenstruktur.
// Sie kann als Vector3df implementiert werden mit Farbanteil von 0 bis 1.
// Vor Setzen eines Pixels auf eine bestimmte Farbe (z.B. 8-Bit-Farbtiefe),
// kann der Farbanteil mit 255 multipliziert  und der Nachkommaanteil verworfen werden.


// Das "Material" der Objektoberfläche mit ambienten, diffusem und reflektiven Farbanteil.


// Ein "Objekt", z.B. eine Kugel oder ein Dreieck, und dem zugehörigen Material der Oberfläche.
// Im Prinzip ein Wrapper-Objekt, das mindestens Material und geometrisches Objekt zusammenfasst.
// Kugel und Dreieck finden Sie in geometry.h/tcc


// verschiedene Materialdefinition, z.B. Mattes Schwarz, Mattes Rot, Reflektierendes Weiss, ...
// im wesentlichen Variablen, die mit Konstruktoraufrufen initialisiert werden.


// Die folgenden Werte zur konkreten Objekten, Lichtquellen und Funktionen, wie Lambertian-Shading
// oder die Suche nach einem Sehstrahl für das dem Augenpunkt am nächsten liegenden Objekte,
// können auch zusammen in eine Datenstruktur für die gesammte zu
// rendernde "Szene" zusammengefasst werden.

// Die Cornelbox aufgebaut aus den Objekten
// Am besten verwendet man hier einen std::vector< ... > von Objekten.

// Punktförmige "Lichtquellen" können einfach als Vector3df implementiert werden mit weisser Farbe,
// bei farbigen Lichtquellen müssen die entsprechenden Daten in Objekt zusammengefaßt werden
// Bei mehreren Lichtquellen können diese in einen std::vector gespeichert werden.

// Sie benötigen eine Implementierung von Lambertian-Shading, z.B. als Funktion
// Benötigte Werte können als Parameter übergeben werden, oder wenn diese Funktion eine Objektmethode eines
// Szene-Objekts ist, dann kann auf die Werte teilweise direkt zugegriffen werden.
// Bei mehreren Lichtquellen muss der resultierende diffuse Farbanteil durch die Anzahl Lichtquellen geteilt werden.

// Für einen Sehstrahl aus allen Objekte, dasjenige finden, das dem Augenpunkt am nächsten liegt.
// Am besten einen Zeiger auf das Objekt zurückgeben. Wenn dieser nullptr ist, dann gibt es kein sichtbares Objekt.

// Die rekursive raytracing-Methode. Am besten ab einer bestimmten Rekursionstiefe (z.B. als Parameter übergeben) abbrechen.


void raytrace(Camera *camera, Scene *scene, Screen *screen) {
    screen->clear();
    for (size_t x = 0.0; x < screen->getWidth(); x++) {
        for (size_t y = 0; y < screen->getHeight(); y++) {
            const Ray<float, 3> ray = camera->getRay(x, y);
            /* START: code that calculates the color of a pixel*/
            Color color = camera->trace(scene, ray, 20);
            /* END: code that calculates the color of a pixel*/
            screen->setPixel(x, y, color);
        }
    }
}

std::ostream &operator<<(std::ostream &out, const Screen &screen) {
    out << "P3" << std::endl;
    out << screen.getWidth() << " " << screen.getHeight() << std::endl;
    out << "255" << std::endl;
    for (size_t y = 0u; y < screen.getHeight(); y++) {
        for (size_t x = 0u; x < screen.getWidth(); x++) {
            std::cout << (unsigned short) (screen.getPixel(x, y).getRed() * 255) << " "
                      << (unsigned short) (screen.getPixel(x, y).getGreen() * 255) << " "
                      << (unsigned short) (screen.getPixel(x, y).getBlue() * 255) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return out;
}

int main() {
    Scene scene;
    scene.initialize();

    //todo: create init function for scene

    float aspect_ration = 4.0 / 3.0;

    int height = static_cast<int>(width / aspect_ration);
    height = (height < 1) ? 1 : height;


    // Kamera erstellen
    float focal_length = 2.0;
    float viewport_height = 2.0;
    Vector3df camera_center = {0.0f, 1.0f, 8.0f};
    Screen screen(width, height);
    Camera camera(screen, focal_length, viewport_height, height, width, camera_center);
    raytrace(&camera, &scene, &screen);

    std::cout << screen;
}
