//#ifndef TWODPLOT_H_
//#define TWODPLOT_H_
#include "../utilities/DatabaseMessageConnection.h"
#include "../glut_framework/GlutFramework.h"
#include <map>
#include <deque>
#include <set>
#include <pthread.h>

using namespace glutFramework;

class TwoDPlot : public GlutFramework {

public:
    TwoDPlot(int argc, char **argv, char *remote_host,
            std::set<int> *ports,
            std::map<int, char*> *y_axis_labels,
            std::map<int, int> *key_to_neuronid_map,
            std::map<int, struct colour> *neuron_id_to_colour_map,
            float plot_time_ms, float timestep_ms, int n_neurons,
            DatabaseMessageConnection *database_message_connection);
    void init();
    void display(float time);
    void reshape(int width, int height);
    void keyboardUp(unsigned char key, int x, int y);
    virtual ~TwoDPlot();

private:
    void printgl(float x, float y, void *font_style, char* format, ...);
    void printglstroke(float x, float y, float size, float rotate,
        char* format, ...);
    void safelyshut();
    void accumSpikes();
    void textureDisplay();
    void polygonDisplay();
    void drawGrid();
    void drawSquare(float x, float y, float r, float g, float b);
    
    const static int WINDOW_BORDER = 110;
    const static int INIT_WINDOW_WIDTH = 800;
    const static int INIT_WINDOW_HEIGHT = 800;
    const static double FRAMES_PER_SECOND = 60.0;
    const static int INIT_WINDOW_X = 100;
    const static int INIT_WINDOW_Y = 100;
    const static int SIZE_WIDTH = 128;
    const static int SIZE_HEIGHT = 128;
    
    float plot_time_ms;
    float timestep_ms;
    int n_neurons;
    int window_width;
    int window_height;
    unsigned char img[SIZE_WIDTH*SIZE_HEIGHT*3];
    int population_width;
    int population_height;
    int block_size;
    
    std::deque<std::pair<int, int> > points_to_draw;
    pthread_mutex_t point_mutex;

    std::map<int, struct colour> *neuron_id_to_colour_map;
    std::map<int, int> *key_to_neuronid_map;
    std::map<int, char*> *y_axis_labels;

    DatabaseMessageConnection *database_message_connection;
};

//#endif /* TWODPLOT_H_ */
