#include "checkpoint.h"
#include "main.h"

Checkpoint::Checkpoint(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 5;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
     
    float c1_r = 5 ; 
    this->radius = c1_r ; 

    static GLfloat vertex_buffer_data[] = {
        -2.5, 0.0, 0.0,
        -2.5, -8.0, 0.0,
        2.5, 0.0, 0.0,
        -2.5, -8.0, 0.0,
        2.5, -8.0, 0.0,
        2.5, 0.0, 0.0,
        5.0, -8.0, 0.0,
        -5.0, -8.0, 0.0,
        0.0, -12.0, 0.0,
    } ; 
  
    this->Mountain = create3DObject(GL_TRIANGLES, 9, vertex_buffer_data, color  , GL_FILL);
    // this->Lava = create3DObject(GL_TRIANGLES, 60, vertex_buffer_data_lava, COLOR_LAVA, GL_FILL ) ; 
}

void Checkpoint::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    this->rotation += 3 ; 
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->Mountain);
    // draw3DObject(this->Lava) ;   
    // draw3DObject(this->object2) ; 
    // draw3DObject(this->object3) ; 
}

void Checkpoint::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

glm::vec3 Checkpoint::return_position(){
    return this->position ; 
}

float Checkpoint::return_radius(){
    return this->radius ; 
}

void Checkpoint::tick() {
    // this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

