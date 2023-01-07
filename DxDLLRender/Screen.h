// ладно держите беграунд но при одном условии сука не пастите в него уебанское
class dot
{
public:
	dot(Vector3 p, Vector3 v) {
		m_vel = v;
		m_pos = p;
	}

	void update();
	void draw();

	Vector3 m_pos, m_vel;
};
std::vector<dot*> dots = { };
void dot::update() {
	auto opacity = 240 / 255.0f;

	m_pos += m_vel * (opacity);
}
void dot::draw() {
	int opacity = 55.0f * (240 / 200.0f);

	ImGui::GetWindowDrawList()->AddRectFilled({ m_pos.x - 2, m_pos.y - 2 }, { m_pos.x + 2, m_pos.y + 2 }, ImColor(Colors::TextColor));

	auto t = std::find(dots.begin(), dots.end(), this);
	if (t == dots.end()) {
		return;
	}

	for (auto i = t; i != dots.end(); i++) {
		if ((*i) == this) continue;

		auto dist = (m_pos - (*i)->m_pos).length_2d();

		if (dist < 90) {
			int alpha = opacity * (dist / 90);
			ImGui::GetWindowDrawList()->AddLine({ m_pos.x - 1, m_pos.y - 2 }, { (*i)->m_pos.x - 2, (*i)->m_pos.y - 1 }, ImColor(Colors::TextColor));
		}
	}
}
void dot_draw() {
	struct screen_size {
		int x, y;
	}; screen_size sc;
	sc.x = 1920, sc.y = 1080;

	int s = rand() % 9;

	if (s == 0) {
		dots.push_back(new dot(Vector3(rand() % (int)sc.x, -16, 0), Vector3((rand() % 7) - 2, rand() % 2 + 1, 0)));
	}
	else if (s == 1) {
		dots.push_back(new dot(Vector3(rand() % (int)sc.x, (int)sc.y + 16, 0), Vector3((rand() % 7) - 2, -1 * (rand() % 2 + 1), 0)));
	}
	else if (s == 2) {
		dots.push_back(new dot(Vector3(-16, rand() % (int)sc.y, 0), Vector3(rand() % 2 + 1, (rand() % 7) - 2, 0)));
	}
	else if (s == 3) {
		dots.push_back(new dot(Vector3((int)sc.x + 16, rand() % (int)sc.y, 0), Vector3(-1 * (rand() % 2 + 1), (rand() % 7) - 2, 0)));
	}

	auto alph = 135.0f * (240 / 255.0f);
	auto a_int = (int)(alph);

	ImGui::GetWindowDrawList()->AddRectFilled({ 0, 0 }, { (float)sc.x, (float)sc.y }, ImColor(a_int, 0, 0, 0));

	for (auto i = dots.begin(); i < dots.end();) {
		if ((*i)->m_pos.y < -20 || (*i)->m_pos.y > sc.y + 20 || (*i)->m_pos.x < -20 || (*i)->m_pos.x > sc.x + 20) {
			delete (*i);
			i = dots.erase(i);
		}
		else {
			(*i)->update();
			i++;
		}
	}

	for (auto i = dots.begin(); i < dots.end(); i++) {
		(*i)->draw();
	}
}