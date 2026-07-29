package project.util;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeMap;

import com.mysql.cj.x.protobuf.MysqlxCrud.Find;

public class IntervalMap<T> {
	TreeMap<Integer, Segment> treeMap = new TreeMap<Integer, Segment>();
	
	private class Segment {
		final int start, end;
	    final T value;
	    
		private Segment(Integer keyBegin, Integer keyEnd, T value) {
			this.start = keyBegin;
			this.end = keyEnd;
			this.value = value;
			
			treeMap.put(keyBegin, this);
		}
		
		void destroy() {
			treeMap.remove(start);
		}
		
		boolean contains(int x) {
		      return start <= x && x < end;
		}	
 	}
	
	  private Segment upper(int x) {
		    return extract(treeMap.ceilingEntry(x));
	  }

	  private Segment lower(int x) {
		    return extract(treeMap.floorEntry(x));
	  }
	
	  private Segment extract(Entry<Integer, Segment> e) {
		    return e != null ? e.getValue() : null;
	  }
	  
	  
	  private Segment find(int x) {
	    final Segment prev = lower(x);
	    
	    return prev != null && prev.contains(x) ? prev : upper(x);
	  }
	
	
	
	public void assign(Integer keyBegin, Integer keyEnd, T value) {
		if (keyBegin > keyEnd) 
			return;
		
		final Segment segment =  find(keyBegin);
		
		if (segment==null) {
			new Segment(keyBegin, keyEnd, value);
		}else if (keyBegin < segment.start) {
			if (keyEnd < segment.start) 
				new Segment(keyBegin, keyEnd, value);
			else if(keyEnd < segment.end) {
				segment.destroy();
		        new Segment(keyBegin, keyEnd, value);
		        new Segment(keyBegin, segment.end, segment.value);
			}else {
				segment.destroy();
		        new Segment(keyBegin, segment.end, value);
		        assign(segment.end, keyEnd, value);
			}
		}else 
			throw new IllegalStateException();	
	}
	
	
	public T get(int x) {
	    final Segment s = lower(x);
	    return s != null && s.contains(x) ? s.value : null;
	}
}
	
