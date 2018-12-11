package TankWar;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

import javax.swing.JFrame;

class Wall {
	int x, y;
	boolean live = true;

	public Wall() {
		x = 0;
		y = 0;
	}

	public Wall(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public void hit(int x1, int y1) {
		if (x1 == x && y1 == y) {
			live = false;
		}
	}

	public boolean getlive() {
		return live;
	}
}

class Map {
	// hang lie
	int map[][] = new int[32][32];// 0 empty, 1 无敌wall, 2 wall, 3 bird

	public void readmap() throws IOException {
		String path = "./image/map.txt";
		File file = new File(path);
		InputStreamReader reader = new InputStreamReader(new FileInputStream(file));
		BufferedReader br = new BufferedReader(reader);
		String line = "p";
		int x = 0;
		while (line != null) {
			line = br.readLine();
			if (line == null) {
				break;
			}
			// System.out.println(line);
			int y = 0;
			for (int i = 0; i < line.length(); i++) {
				if (line.charAt(i) >= '0' && line.charAt(i) <= '9') {
					map[x][y] = line.charAt(i) - '0';
					y++;
				}
			}
			x++;
		}
	}

	public Map() throws IOException {
		readmap();
	}

	public void setInWall(int x, int y) {
		map[x][y] = 1;
	}

	public int[][] getmap() {
		return map;
	}

	public void setWall(int x, int y) {
		map[x][y] = 2;
	}
}

class UI extends JFrame {
	protected Map map;
	protected Image floor = Toolkit.getDefaultToolkit().getImage("./image/floor.jpg");
	protected Image inWall = Toolkit.getDefaultToolkit().getImage("./image/steels.gif");
	protected Image star = Toolkit.getDefaultToolkit().getImage("./image/star.gif");
	protected Image wall = Toolkit.getDefaultToolkit().getImage("./image/walls.gif");
	protected Image tank = Toolkit.getDefaultToolkit().getImage("./image/y_tank.gif");

	public UI() {
		super("Tank War");
		this.setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		paint(this.getGraphics());
	}

	public UI(Map m) {
		super("Tank War");
		this.setSize(1010, 600);
		this.setBackground(Color.WHITE);
		this.setVisible(true);
		this.getContentPane().add(new MainPanel(50, 50));
		this.revalidate();
		// this.repaint();
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		map = m;
		paint(this.getGraphics());
	}

	public void setmap(Map m) {
		map = m;
	}

	public void paint(Graphics g) {
		g.drawImage(star, 5 + 40 * 11, 40 * 12, 120, 120, this);
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 25; j++) {
				if (map.getmap()[i][j] == 1) {
					g.drawImage(inWall, 5 + 40 * j, 40 * i, 40, 40, this);
				}
				if (map.getmap()[i][j] == 0) {
					g.drawImage(floor, 5 + 40 * j, 40 * i, 40, 40, this);
				}
				if (map.getmap()[i][j] == 2) {
					g.drawImage(wall, 5 + 40 * j, 40 * i, 40, 40, this);
				}
			}
		}

	}

	public static void main(String[] args) throws IOException {
		Map m;
		m = new Map();
		UI a = new UI(m);
		a.setResizable(false);
	}

}
