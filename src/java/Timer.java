import java.util.concurrent.TimeUnit;

public class Timer {
	private long startTimeMillis;
	private long endTimeMillis;
	
	public Timer start() {
		reset();
		this.startTimeMillis = System.currentTimeMillis();
		return this;
	}
	
	public Timer stop() {
		this.endTimeMillis = System.currentTimeMillis();
		return this;
	}
	
	public long timeCosts() {
		return timeCosts(TimeUnit.MILLISECONDS);
	}
	
	public long timeCosts(TimeUnit unit) {
		long timeCosts = (endTimeMillis - startTimeMillis);
		return TimeUnit.MILLISECONDS.convert(timeCosts, unit);
	}
	
	public void reset() {
		this.startTimeMillis = this.endTimeMillis = 0;
	}

	public long getStartTimeMillis() {
		return startTimeMillis;
	}

	public void setStartTimeMillis(long startTimeMillis) {
		this.startTimeMillis = startTimeMillis;
	}

	public long getEndTimeMillis() {
		return endTimeMillis;
	}

	public void setEndTimeMillis(long endTimeMillis) {
		this.endTimeMillis = endTimeMillis;
	}
}

