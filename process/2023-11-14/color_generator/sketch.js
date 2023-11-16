let colors = ['#ADD8E6', '#FFA500', '#9400D3', '#FFFF00', '#808000', '#556B2F', '#228B22', '#000000', '#8B4513', '#FF0000', '#2F4F4F', '#D3D3D3', '#FFFF00', '#A52A2A', '#FFC0CB', '#FFB6C1', '#000080', '#FF4500', '#8A2BE2', '#00CED1', '#E6E6FA', '#0000CD', '#8B0000', '#FFFFFF']; // Liste de couleurs

function setup() {
  createCanvas(400, 200);
  pickColor(); // Choisir une couleur initiale
}

function draw() {
  // Le dessin principal peut être laissé vide
}

function mouseClicked() {
  pickColor(); // Choisir une nouvelle couleur à chaque clic
  redraw(); // Redessiner le fond avec la nouvelle couleur
}

function pickColor() {
  background(random(colors)); // Choisir une couleur aléatoire dans la liste et redessiner le fond
}
