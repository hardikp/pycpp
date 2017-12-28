enum EventType_t {
  market_book = 1,
  news = 2,
  twitter = 3,
  other = 4,
};

enum IndicatorType_t {
  moving_average = 1,
  sentiment = 2,
  other = 3,
};

class TimeListener {
public:
  virtual ~TimeListener(){};
  virtual void OnTimePeriodUpdate() = 0;
};

class EventListener {
public:
  virtual ~EventListener(){};
  virtual void OnEvent(EventType_t event_type, double event_value) = 0;
};

class IndicatorListener {
public:
  virtual ~IndicatorListener(){};
  virtual void OnIndicatorUpdate(IndicatorType_t indicator_type,
                                 double indicator_value) = 0;
};
